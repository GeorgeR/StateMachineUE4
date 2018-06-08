#include "SMStateMachine.h"


bool USMStateMachine::GoToState_Implementation(FName StateName)
{
	if (!States.Contains(StateName))
		return false;

	auto NextState = States[StateName];

	if (CurrentState != nullptr)
		CurrentState->ExitState(NextState);

	NextState->EnterState(CurrentState);
	CurrentState = NextState;

	return true;
}