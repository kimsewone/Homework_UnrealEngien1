// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
   
    GetWorldTimerManager().SetTimer(TimeHandle, this, &AMyActor::Move, 1.f, true);
    
}
// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyActor::Move()
{
    FVector2D CurPos(GetActorLocation().X, GetActorLocation().Y);
    FVector2D MovePos = Step();
    FVector2D ArrivalPos = CurPos  + MovePos ;
    FVector2D DistPos = ArrivalPos - CurPos;
  
    UE_LOG(LogTemp,Warning, TEXT("Move X : %f / Y : %f / Distance : %f / CuPosX : %f / CuPosY : %f "), MovePos.X, MovePos.Y , sqrtf(DistPos.X* DistPos.X + DistPos.Y* DistPos.Y), ArrivalPos.X, ArrivalPos.Y);
   
    SetActorLocation(FVector(ArrivalPos.X , ArrivalPos.Y, 0.f));

   /* float Dist = FVector2D::Distance(NextPos, CurPos);
    UE_LOG(LogTemp,Warning, TEXT("Distance : %f"), Dist);*/

    if (10  <= VectorArrayIdx)
    {
        int32 RandEvent = CreateEvent();
        UE_LOG(LogTemp, Warning, TEXT("EVent %d"), RandEvent);

        UE_LOG(LogTemp, Warning, TEXT("MOVE END!!"));
        GetWorldTimerManager().ClearTimer(TimeHandle);
    }
}
FVector2D AMyActor::Step()
{
    FVector2D NextPos(FMath::RandRange(0, 1), FMath::RandRange(0, 1));
    VectorArrayIdx++;

    return NextPos;
}

int32 AMyActor::CreateEvent()
{
    return FMath::RandRange(0, 1);
}

