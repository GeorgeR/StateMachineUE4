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
	bool GoToState(const FString& StateName);
	virtual bool GoToState_Implementation(const FString& StateName) = 0;
};

#define DECLARE_STATE_MACHINE()														\
public:																				\
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)									\
	FString StateName;																\
																					\
	FString GetName_Implementation() const override { return StateName; }			\
																					\
	bool GoToState_Implementation(const FString& StateName) override;				\
																					\
private:																			\
	UPROPERTY()																		\
	TMap<FString, TScriptInterface<ISMStateInterface>> States;						\
																					\
	UPROPERTY()																		\
	TScriptInterface<ISMStateInterface> CurrentState;


#define DEFINE_STATE_MACHINE(ClassName)															\
	bool ClassName::GoToState_Implementation(const FString& StateName)							\
	{																							\
		if (!States.Contains(StateName))														\
			return false;																		\
																								\
		auto NextState = States[StateName];														\
																								\
		if (CurrentState != nullptr)															\
			ISMStateMachineInterface::Execute_ExitState(CurrentState.GetObject(), NextState);	\
																								\
		ISMStateMachineInterface::Execute_EnterState(NextState.GetObject(), CurrentState);		\
		CurrentState = NextState;																\
																								\
		return true;																			\
	}
