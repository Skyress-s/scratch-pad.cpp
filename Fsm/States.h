#pragma once

// #include "Turnstile.h"
#include "TBaseState.h"

#include <optional>
#include <string>
#include <variant>




namespace states
{
// using namespace std::chrono_literals;


// template <>
// TOptState TBaseState::process(const UpdateEvent& event);
// template <>
// TOptState TBaseState::process(const CoolEvent& event);

class Start : public TBaseState
// class Start
{
public:
	explicit Start(std::reference_wrapper<fsm_state_transitions::FSM> context)
		: TBaseState(context)
		// : m_Context(context)
	{
	}

	std::string getState() const
	{
		return "Start";
	}

	TOptState process(const UpdateEvent& event);
	TOptState process(const CoolEvent& Event);

private:
	// std::reference_wrapper<fsm_state_transitions::FSM> m_Context;
};


class End : public TBaseState
// class End
{
public:
	explicit End(std::reference_wrapper<fsm_state_transitions::FSM> context)
	: TBaseState(context)
		// : m_Context(context)
	{
	}

	std::string getState() const
	{
		return "End";
	}

	TOptState process(const UpdateEvent& event);

	// Generate a process for all event types we did not use
	template <typename EventType>
	TOptState process(EventType)
	{
		return std::nullopt;
	}

};
}
