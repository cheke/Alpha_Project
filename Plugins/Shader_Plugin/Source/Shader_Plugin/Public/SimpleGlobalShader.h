// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"

/**
 * 
 */
class SHADER_PLUGIN_API FSimpleGlobalShaderVS : public FGlobalShader
{
    DECLARE_SHADER_TYPE(FSimpleGlobalShaderVS,Global);

public:
    FSimpleGlobalShaderVS();
    FSimpleGlobalShaderVS(const FGlobalShaderType::CompiledShaderInitializerType &Initializer);
    ~FSimpleGlobalShaderVS();


    // FShader interface
public:
    virtual bool Serialize(FArchive &Ar) override;
    static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment);
    static bool ShouldCache(EShaderPlatform Platform);
};

class SHADER_PLUGIN_API FSimpleGlobalShaderPS : public FGlobalShader
{
    DECLARE_SHADER_TYPE(FSimpleGlobalShaderPS,Global);

public:
    FSimpleGlobalShaderPS();
    FSimpleGlobalShaderPS(const FGlobalShaderType::CompiledShaderInitializerType &Initializer);
    ~FSimpleGlobalShaderPS();

    // FShader interface
public:
    virtual bool Serialize(FArchive &Ar) override;
    static void ModifyCompilationEnvironment(EShaderPlatform Platform, FShaderCompilerEnvironment& OutEnvironment);
    static bool ShouldCache(EShaderPlatform Platform);
};
