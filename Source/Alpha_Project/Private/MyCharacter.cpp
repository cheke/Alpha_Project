#include "Public/MyCharacter.h"
#include "Engine.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

 //  PixelShading = new FPixelShaderUsageExample(PixelShaderTopLeftColor,
 //                                               GetWorld()->Scene->GetFeatureLevel());

}

void AMyCharacter::BeginDestroy()
{
    Super::BeginDestroy();

   // if (PixelShading) {
   //         delete PixelShading;
   // }
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    static const FString Message(TEXT("Hello World: "));
    //int32 MyNumber = 99;
    //static const FString MessageNumber = FString::FromInt(MyNumber);

    GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, Message);
  //  if( PixelShading ){
  //      PixelShading->ExecuteShader(DemoRenderTarget);
  //  }

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

