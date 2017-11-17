#pragma once

#include "CoreMinimal.h"
#include "RHIDefinitions.h"
#include "RHIResources.h"
#include "TextureRenderTarget2D.h"

/**
 * 
 */
class SHADER_PLUGIN_API FShaderUsageExample
{
public:
    FShaderUsageExample(FColor StartColor, ERHIFeatureLevel::Type ShaderFeatureLevel);
    ~FShaderUsageExample();

    void ExecuteShader(UTextureRenderTarget2D* RenderTarget);
    void ExecuteShaderInternally();

private:
    ERHIFeatureLevel::Type FeatureLevel;

    FTexture2DRHIRef CurrentTexture;
    FTexture2DRHIRef TextureParameter;
    UTextureRenderTarget2D* CurrentRenderTarget;

};
