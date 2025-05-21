//
// Created by szeth on 14/05/25.
//

#pragma once
#include "TBaseState.h"

namespace states
{
// class End : public TBaseState
	class End
{
public:
	explicit End(std::reference_wrapper<fsm_state_transitions::FSM> context)
		// : TBaseState(context)
	: m_Context(context)
	{
	}

	std::string getState() const
	{
		return "End";
	}

	TOptState process(const UpdateEvent& event);
		TOptState process(const CoolEvent& event);

	// Generate a process for all event types we did not use
	// template <typename EventType>
	// TOptState process(EventType)
	// {
		// return std::nullopt;
	// }
 	std::reference_wrapper<fsm_state_transitions::FSM> m_Context;
};
} // states
