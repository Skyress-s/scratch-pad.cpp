#pragma once

// #include "Turnstile.h"

#include <optional>
#include <string>
#include <variant>

#include "../CoroDefs.h"


namespace fsm_state_transitions
{
class FSM;
}

struct UpdateEvent
{
	explicit UpdateEvent(Coro::push_type& Coro)
		: m_Coro(Coro)
	{
	}

	Coro::push_type& m_Coro;
};

struct CoolEvent
{
};


namespace states
{
// using namespace std::chrono_literals;

class Start;
class End;

using TStateVariant =
std::variant<Start, End>;

using TOptState = std::optional<TStateVariant>;

class TBaseState
{
public:
	explicit TBaseState(std::reference_wrapper<fsm_state_transitions::FSM> context) : m_Context(context)
	{
	}

	template <typename EventType>
	TOptState process(EventType);
	// {
	// return TOptState{};
	// return std::nullopt;
	// }

protected:
	std::reference_wrapper<fsm_state_transitions::FSM> m_Context;
};

template <>
TOptState TBaseState::process(const UpdateEvent& event);
template <>
TOptState TBaseState::process(const CoolEvent& event);

class Start
{
public:
	explicit Start(std::reference_wrapper<fsm_state_transitions::FSM> context)
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
	// Generate a process for all event types we did not use
	template <typename EventType>
	TOptState process(EventType)
	{
		return std::nullopt;
	}

	std::reference_wrapper<fsm_state_transitions::FSM> m_Context;
};
} // namespace states
