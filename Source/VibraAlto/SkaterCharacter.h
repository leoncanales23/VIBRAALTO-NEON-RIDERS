#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SkaterCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;

/** Personaje en tercera persona (placeholder: capsula + tabla). WASD mover, mouse mirar, Espacio saltar. */
UCLASS()
class VIBRAALTO_API ASkaterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASkaterCharacter();

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveAlong(EAxis::Type Axis, float Value);
	void KeyForward(float V) { MoveAlong(EAxis::X,  V); }
	void KeyBack(float V)    { MoveAlong(EAxis::X, -V); }
	void KeyRight(float V)   { MoveAlong(EAxis::Y,  V); }
	void KeyLeft(float V)    { MoveAlong(EAxis::Y, -V); }
	void LookUp(float Value);
	void Turn(float Value);

	UPROPERTY(VisibleAnywhere) USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere) UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* BodyMesh;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* BoardMesh;
};
