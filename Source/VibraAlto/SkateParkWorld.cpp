#include "SkateParkWorld.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

UStaticMeshComponent* ASkateParkWorld::MakeBlock(const TCHAR* Name, UStaticMesh* Mesh, const FVector& Loc, const FRotator& Rot, const FVector& Scale)
{
	UStaticMeshComponent* C = CreateDefaultSubobject<UStaticMeshComponent>(Name);
	C->SetupAttachment(Root);
	C->SetStaticMesh(Mesh);
	C->SetRelativeLocation(Loc);
	C->SetRelativeRotation(Rot);
	C->SetRelativeScale3D(Scale);
	return C;
}

ASkateParkWorld::ASkateParkWorld()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	// El cubo basico mide 100x100x100; las escalas de abajo estan pensadas para eso.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (!CubeMesh.Succeeded())
	{
		return;
	}
	UStaticMesh* Cube = CubeMesh.Object;

	// Piso 2000x2000, su cara superior queda en Z=0
	Floor = MakeBlock(TEXT("Floor"), Cube, FVector(0, 0, -50), FRotator::ZeroRotator, FVector(20, 20, 1));

	// Rampas: suben hacia los extremos (Pitch inclina el eje X)
	RampLeft  = MakeBlock(TEXT("RampLeft"),  Cube, FVector(-500, 0, 30), FRotator(-15, 0, 0), FVector(5, 2, 0.4f));
	RampRight = MakeBlock(TEXT("RampRight"), Cube, FVector( 500, 0, 30), FRotator( 15, 0, 0), FVector(5, 2, 0.4f));

	// Cajon de trucos 200x200x60
	Box = MakeBlock(TEXT("TrickBox"), Cube, FVector(0, 300, 30), FRotator::ZeroRotator, FVector(2, 2, 0.6f));

	// Rail horizontal a lo largo de Y, con dos soportes
	Rail      = MakeBlock(TEXT("Rail"),      Cube, FVector(0, -300, 90),  FRotator::ZeroRotator, FVector(0.1f, 5, 0.1f));
	RailPostA = MakeBlock(TEXT("RailPostA"), Cube, FVector(0, -520, 45),  FRotator::ZeroRotator, FVector(0.1f, 0.1f, 0.9f));
	RailPostB = MakeBlock(TEXT("RailPostB"), Cube, FVector(0, -80, 45),   FRotator::ZeroRotator, FVector(0.1f, 0.1f, 0.9f));
}
