//
// Created by szeth on 14/05/25.
//

#include "StartState.h"
#include "EndState.h"

namespace states {

TOptState Start::process(const UpdateEvent& event)
{
	event.m_Coro("Im in Start!");
	return End(m_Context);
	// return End();
}

TOptState Start::process(const CoolEvent& Event)
{
	return End(m_Context);
}
} // states