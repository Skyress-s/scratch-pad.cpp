//
// Created by szeth on 14/05/25.
//

#pragma once
#include <optional>
#include <variant>
#include <functional>

#include "../CoroDefs.h"

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

namespace fsm_state_transitions
{
class FSM;
}

namespace states
{

class Start;
class End;

using TStateVariant =
std::variant<Start, End>;

using TOptState = std::optional<TStateVariant>;

// template <typename T>
// class TBaseState
// {
// public:
// 	explicit TBaseState(std::reference_wrapper<fsm_state_transitions::FSM> context) : m_Context(context)
// 	{
// 	}
//
// 	// Sadly I cannot get the this template to create functions for all unused handled events
// 	// template <typename EventType>
// 	// TOptState process(EventType);
// 	// {
// 	// return std::nullopt;
// 	// }
//
// protected:
// 	std::reference_wrapper<fsm_state_transitions::FSM> m_Context;
// };
} // states
