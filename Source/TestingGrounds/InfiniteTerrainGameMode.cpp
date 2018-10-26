// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav Mesh Bounds Volume Pool"));
}
void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	//NavMeshBoundsVolume_1
	TActorIterator<ANavMeshBoundsVolume> VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);		
		++VolumeIterator;
	}
}
void AInfiniteTerrainGameMode::AddToPool(class ANavMeshBoundsVolume *VolumeToAdd)
{	
	//UE_LOG(LogTemp, Warning, TEXT("Found Volume: %s"), *VolumeToAdd->GetName());
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}

