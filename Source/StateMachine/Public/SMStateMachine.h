#pragma once

#include "CoreMinimal.h"
#include "UObject/ScriptInterface.h"
#include "SMState.h"
#include "SMStateMachineInterface.h"

#include "SMStateMachine.generated.h"

// UObject base class
UCLASS(Abstract)
class STATEMACHINE_API USMStateMachine 
	: public USMState,
	public ISMStateMachineInterface
{
	GENERATED_BODY()

public:
	FString GetName_Implementation() const override { return StateName; }

	bool GoToState_Implementation(const FString& StateName) override;

private:
	UPROPERTY()
	TMap<FString, TScriptInterface<ISMStateInterface>> States;

	UPROPERTY()
	TScriptInterface<ISMStateInterface> CurrentState;
};
