//
// Created by szeth on 14/05/25.
//

#include "EndState.h"
#include "StartState.h"

namespace states {
TOptState End::process(const UpdateEvent& event)
{
	event.m_Coro("Im in Start!");
	return std::optional<std::variant<Start, End>>(Start(m_Context));
}
} // states