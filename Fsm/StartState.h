//
// Created by szeth on 14/05/25.
//

#pragma once
// #include <functional>
#include "TBaseState.h"

namespace states {

// class Start : public TBaseState
class Start
{
public:
	explicit Start(std::reference_wrapper<fsm_state_transitions::FSM> context)
		// : TBaseState(context)
		: m_Context(context)
	{
	}

	std::string getState() const
	{
		return "Start";
	}

	TOptState process(const UpdateEvent& event);
	TOptState process(const CoolEvent& Event);

private:
 	std::reference_wrapper<fsm_state_transitions::FSM> m_Context;
};

} // states
