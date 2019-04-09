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
	FString GetName() const;
	virtual FString GetName_Implementation() const = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|State")
	void InitState(const TScriptInterface<ISMStateMachineInterface>& Machine);
	virtual void InitState_Implementation(const TScriptInterface<ISMStateMachineInterface>& Machine) { }

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|State")
	void EnterState(const TScriptInterface<ISMStateInterface>& PreviousState);
	virtual void EnterState_Implementation(const TScriptInterface<ISMStateInterface>& PreviousState) { }

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StateMachine|State")
	void ExitState(const TScriptInterface<ISMStateInterface>& NextState);
	virtual void ExitState_Implementation(const TScriptInterface<ISMStateInterface>& NextState) { }
};
