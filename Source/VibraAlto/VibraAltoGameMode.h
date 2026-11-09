#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VibraAltoGameMode.generated.h"

/** Usa ASkaterCharacter como jugador y, si el nivel no tiene skatepark, lo crea solo. */
UCLASS()
class VIBRAALTO_API AVibraAltoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AVibraAltoGameMode();
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
