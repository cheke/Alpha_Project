#include "SimpleGlobalShader.h"
#include "ShaderParameterUtils.h"

// VERTEX SHADER
FSimpleGlobalShaderVS::FSimpleGlobalShaderVS()
{

}

FSimpleGlobalShaderVS::FSimpleGlobalShaderVS(const FGlobalShaderType::CompiledShaderInitializerType &Initializer)
	: FGlobalShader(Initializer)
{

}

FSimpleGlobalShaderVS::~FSimpleGlobalShaderVS()
{

}

bool FSimpleGlobalShaderVS::Serialize(FArchive &Ar)
{
    bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
    //Ar <<
    return bShaderHasOutdatedParameters;
}

void FSimpleGlobalShaderVS::ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment &OutEnvironment)
{
    FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
}

bool FSimpleGlobalShaderVS::ShouldCache(EShaderPlatform Platform)
{
    return IsFeatureLevelSupported(Platform, ERHIFeatureLevel::SM4);
}

IMPLEMENT_SHADER_TYPE(, FSimpleGlobalShaderVS, TEXT("/Plugin/Shader_Plugin/Private/MyShader.usf"), TEXT("MainVS"), SF_Vertex)

// PIXEL SHADER
FSimpleGlobalShaderPS::FSimpleGlobalShaderPS()
{

}

FSimpleGlobalShaderPS::FSimpleGlobalShaderPS(const FGlobalShaderType::CompiledShaderInitializerType &Initializer)
	: FGlobalShader(Initializer)
{
	MyColorParameter.Bind(Initializer.ParameterMap, TEXT("MyColor"), SPF_Mandatory);
}

FSimpleGlobalShaderPS::~FSimpleGlobalShaderPS()
{

}

bool FSimpleGlobalShaderPS::Serialize(FArchive &Ar)
{
    bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
	Ar << MyColorParameter;
    return bShaderHasOutdatedParameters;
}

void FSimpleGlobalShaderPS::ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment &OutEnvironment)
{
    FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
	// Add your own defines for the shader code
	OutEnvironment.SetDefine(TEXT("MY_DEFINE"), 1);
}

bool FSimpleGlobalShaderPS::ShouldCache(EShaderPlatform Platform)
{
    return IsFeatureLevelSupported(Platform, ERHIFeatureLevel::SM4);
}

void FSimpleGlobalShaderPS::SetColor(FRHICommandList& RHICmdList, const FLinearColor& Color)
{
	SetShaderValue(RHICmdList, GetPixelShader(), MyColorParameter, Color);
}

IMPLEMENT_SHADER_TYPE(, FSimpleGlobalShaderPS, TEXT("/Plugin/Shader_Plugin/Private/MyShader.usf"), TEXT("MainPS"), SF_Pixel)

