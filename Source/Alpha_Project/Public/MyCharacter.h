#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"
#include "ShaderUsageExample.h"

UCLASS()

class ALPHA_PROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
    UTextureRenderTarget2D* DemoRenderTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShaderDemo)
    FColor PixelShaderTopLeftColor;

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
  //  FShaderUsageExample* PixelShading;

};

