// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleGlobalShader.h"

// VERTEX SHADER
FSimpleGlobalShaderVS::FSimpleGlobalShaderVS()
{

}

FSimpleGlobalShaderVS::FSimpleGlobalShaderVS(const FGlobalShaderType::CompiledShaderInitializerType &Initializer)
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
{

}

FSimpleGlobalShaderPS::~FSimpleGlobalShaderPS()
{

}

bool FSimpleGlobalShaderPS::Serialize(FArchive &Ar)
{
    bool bShaderHasOutdatedParameters = FGlobalShader::Serialize(Ar);
    //Ar <<
    return bShaderHasOutdatedParameters;
}

void FSimpleGlobalShaderPS::ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment &OutEnvironment)
{
    FGlobalShader::ModifyCompilationEnvironment(Platform, OutEnvironment);
}

bool FSimpleGlobalShaderPS::ShouldCache(EShaderPlatform Platform)
{
    return IsFeatureLevelSupported(Platform, ERHIFeatureLevel::SM4);
}

IMPLEMENT_SHADER_TYPE(, FSimpleGlobalShaderPS, TEXT("/Plugin/Shader_Plugin/Private/MyShader.usf"), TEXT("MainPS"), SF_Pixel)

