#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SMStateInterface.h"

#include "SMState.generated.h"

class ISMStateMachineInterface;

// UObject base class
UCLASS(Abstract)
class STATEMACHINE_API USMState 
	: public UObject,
	public ISMStateInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FString StateName;

	FString GetName_Implementation() const override { return StateName; }

	void InitState_Implementation(const TScriptInterface<ISMStateMachineInterface>& Machine) override;

private:
	UPROPERTY()
	TScriptInterface<ISMStateMachineInterface> StateMachine;
};
