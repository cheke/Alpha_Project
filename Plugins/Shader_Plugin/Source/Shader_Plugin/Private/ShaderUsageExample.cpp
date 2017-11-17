#include "ShaderUsageExample.h"
#include "RenderingThread.h"
#include "Shader.h"
#include "RHIUtilities.h"
#include "RHIStaticStates.h"
#include "SimpleGlobalShader.h"

FShaderUsageExample::FShaderUsageExample(FColor StartColor, ERHIFeatureLevel::Type ShaderFeatureLevel)
{
    FeatureLevel = ShaderFeatureLevel;

    CurrentTexture = NULL;
}

FShaderUsageExample::~FShaderUsageExample()
{

}

void FShaderUsageExample::ExecuteShader(UTextureRenderTarget2D *RenderTarget)
{
    check(IsInGameThread());

    CurrentRenderTarget = RenderTarget;

    //This macro sends the function we declare inside to be run on the render thread. What we do is essentially just send this class and tell the render thread to run the internal render function as soon as it can.
    //I am still not 100% Certain on the thread safety of this, if you are getting crashes, depending on how advanced code you have in the start of the ExecutePixelShader function, you might have to use a lock :)
    ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
            FShaderRunner,
            FShaderUsageExample*, PixelShader, this,
            {
                PixelShader->ExecuteShaderInternal();
            }
    );
}

void FShaderUsageExample::ExecuteShaderInternally()
{
    check(IsInRenderingThread());

    FRHICommandListImmediate& RHICmdList = GRHICommandList.GetImmediateCommandList();

    TShaderMapRef<FSimpleGlobalShaderVS> VertexShader(GetGlobalShaderMap(FeatureLevel));
    TShaderMapRef<FSimpleGlobalShaderPS> PixelShader(GetGlobalShaderMap(FeatureLevel));

    CurrentTexture = CurrentRenderTarget->GetRenderTargetResource()->GetRenderTargetTexture();
    SetRenderTarget(RHICmdList, CurrentTexture, FTextureRHIRef());

    // Rendering states to set explicitly, not set by default
    FGraphicsPipelineStateInitializer GraphicsPSOInit;
        RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
        GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
        GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
        GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
        GraphicsPSOInit.PrimitiveType = PT_TriangleStrip;
        GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GTextureVertexDeclaration.VertexDeclarationRHI;
        GraphicsPSOInit.BoundShaderState.VertexShaderRHI = GETSAFERHISHADER_VERTEX(*VertexShader);
        GraphicsPSOInit.BoundShaderState.PixelShaderRHI = GETSAFERHISHADER_PIXEL(*PixelShader);
    SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit);

    FLinearColor color;
    PixelShader->SetColor(RHICmdList, color.Green);

    RHICmdList.CopyToResolveTarget(CurrentRenderTarget->GetRenderTargetResource()->GetRenderTargetTexture(),
                                   CurrentRenderTarget->GetRenderTargetResource()->TextureRHI,
                                   false,
                                   FResolveParams());

}
