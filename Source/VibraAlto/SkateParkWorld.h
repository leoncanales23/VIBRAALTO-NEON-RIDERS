#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkateParkWorld.generated.h"

class UStaticMesh;
class UStaticMeshComponent;

/** Skatepark basico hecho con cubos: piso, 2 rampas, cajon de trucos y rail. */
UCLASS()
class VIBRAALTO_API ASkateParkWorld : public AActor
{
	GENERATED_BODY()

public:
	ASkateParkWorld();

protected:
	UPROPERTY(VisibleAnywhere) USceneComponent* Root;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* Floor;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* RampLeft;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* RampRight;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* Box;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* Rail;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* RailPostA;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* RailPostB;

private:
	UStaticMeshComponent* MakeBlock(const TCHAR* Name, UStaticMesh* Mesh, const FVector& Loc, const FRotator& Rot, const FVector& Scale);
};
