#include "SMStateMachine.h"

bool USMStateMachine::GoToState_Implementation(const FString& Name)
{
	if (!States.Contains(Name))
		return false;

	auto NextState = States[Name];

	if (CurrentState != nullptr)
		ISMStateMachineInterface::Execute_ExitState(CurrentState.GetObject(), NextState);

	ISMStateMachineInterface::Execute_EnterState(NextState.GetObject(), CurrentState);
	CurrentState = NextState;

	return true;
}
