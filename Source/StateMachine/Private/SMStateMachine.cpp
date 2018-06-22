#include "SMStateMachine.h"

bool USMStateMachine::GoToState_Implementation(FName StateName)
{
	if (!States.Contains(StateName))
		return false;

	auto NextState = States[StateName];

	if (CurrentState != nullptr)
		ISMStateMachineInterface::Execute_ExitState(CurrentState.GetObject(), NextState);

	ISMStateMachineInterface::Execute_EnterState(NextState.GetObject(), CurrentState);
	CurrentState = NextState;

	return true;
}