#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SMStateInterface.h"

#include "SMStateMachineInterface.generated.h"

UINTERFACE(MinimalAPI)
class USMStateMachineInterface
	: public USMStateInterface
{
	GENERATED_BODY()
};

class STATEMACHINE_API ISMStateMachineInterface
	: public ISMStateInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|StateMachine")
	TScriptInterface<ISMStateInterface> GetDefaultState();
	virtual TScriptInterface<ISMStateInterface> GetDefaultState_Implementation() { return nullptr; }

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|StateMachine")
	bool GoToState(FName StateName);
	virtual bool GoToState_Implementation(FName StateName) = 0;
};