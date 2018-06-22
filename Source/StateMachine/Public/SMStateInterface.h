#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/ScriptInterface.h"

#include "SMStateInterface.generated.h"

class ISMStateMachineInterface;

UINTERFACE(MinimalAPI)
class USMStateInterface : public UInterface
{
	GENERATED_BODY()
};

class STATEMACHINE_API ISMStateInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|State")
	FName GetName() const;
	virtual FName GetName_Implementation() const = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|State")
	void InitState(const TScriptInterface<ISMStateMachineInterface>& InMachine);
	virtual void InitState_Implementation(const TScriptInterface<ISMStateMachineInterface>& InMachine) { }

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|State")
	void EnterState(const TScriptInterface<ISMStateInterface>& InPreviousState);
	virtual void EnterState_Implementation(const TScriptInterface<ISMStateInterface>& InPreviousState) { }

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|State")
	void ExitState(const TScriptInterface<ISMStateInterface>& InNextState);
	virtual void ExitState_Implementation(const TScriptInterface<ISMStateInterface>& InNextState) { }
};