#include "SMState.h"

void USMState::InitState_Implementation(const TScriptInterface<ISMStateMachineInterface>& Machine)
{
	StateMachine = Machine;
}
