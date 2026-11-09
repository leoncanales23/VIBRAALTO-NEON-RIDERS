#include "SkaterCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UObject/ConstructorHelpers.h"

ASkaterCharacter::ASkaterCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(40.f, 90.f);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 900.f;
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.4f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 450.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Placeholders visibles hasta tener un modelo de skater real
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cylinder(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(GetCapsuleComponent());
	BodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BodyMesh->SetRelativeLocation(FVector(0, 0, -10));
	BodyMesh->SetRelativeScale3D(FVector(0.6f, 0.6f, 1.6f));
	if (Cylinder.Succeeded()) { BodyMesh->SetStaticMesh(Cylinder.Object); }

	BoardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoardMesh"));
	BoardMesh->SetupAttachment(GetCapsuleComponent());
	BoardMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoardMesh->SetRelativeLocation(FVector(0, 0, -85));
	BoardMesh->SetRelativeScale3D(FVector(0.9f, 0.25f, 0.05f));
	if (Cube.Succeeded()) { BoardMesh->SetStaticMesh(Cube.Object); }
}

void ASkaterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Teclas directas: no requiere configurar Input Mappings en el editor
	PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxisKey(EKeys::W, this, &ASkaterCharacter::KeyForward);
	PlayerInputComponent->BindAxisKey(EKeys::S, this, &ASkaterCharacter::KeyBack);
	PlayerInputComponent->BindAxisKey(EKeys::D, this, &ASkaterCharacter::KeyRight);
	PlayerInputComponent->BindAxisKey(EKeys::A, this, &ASkaterCharacter::KeyLeft);
	PlayerInputComponent->BindAxisKey(EKeys::MouseY, this, &ASkaterCharacter::LookUp);
	PlayerInputComponent->BindAxisKey(EKeys::MouseX, this, &ASkaterCharacter::Turn);
}

void ASkaterCharacter::MoveAlong(EAxis::Type Axis, float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator Yaw(0.f, Controller->GetControlRotation().Yaw, 0.f);
		AddMovementInput(FRotationMatrix(Yaw).GetUnitAxis(Axis), Value);
	}
}

void ASkaterCharacter::LookUp(float Value) { AddControllerPitchInput(-Value); }
void ASkaterCharacter::Turn(float Value)   { AddControllerYawInput(Value); }
