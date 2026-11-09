#include "VibraAltoGameMode.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "SkateParkWorld.h"
#include "SkaterCharacter.h"

AVibraAltoGameMode::AVibraAltoGameMode()
{
	DefaultPawnClass = ASkaterCharacter::StaticClass();
}

void AVibraAltoGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UWorld* World = GetWorld();
	if (World && !TActorIterator<ASkateParkWorld>(World))
	{
		World->SpawnActor<ASkateParkWorld>(FVector::ZeroVector, FRotator::ZeroRotator);
	}
}
