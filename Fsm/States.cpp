//
// Created by szeth on 13/05/25.
//

#include "States.h"

template <typename EventType>
states::TOptState states::TBaseState::process(EventType)
{
	return std::nullopt;
}
// states::TOptState states::Start::process(const UpdateEvent& event)
// {
// 	return Middle(_context);
// }
//
// states::TOptState states::Middle::process(const UpdateEvent& event)
// {
// 	if (++m_NumIterations > 10)
// 	{
// 		event.m_Coro("Im in state Middle!");
// 		return End(_context);
// 	}
// 	return std::nullopt;
// }
//
// states::TOptState states::End::process(const UpdateEvent& event)
// {
// 	return Start(_context);
// }
states::TOptState states::Start::process(const UpdateEvent& event)
{
	event.m_Coro("Im in Start!");
	return End(m_Context);
}

states::TOptState states::Start::process(const CoolEvent& Event)
{
	return End(m_Context);
}

states::TOptState states::End::process(const UpdateEvent& event)
{
	event.m_Coro("Im in Start!");
	return Start(m_Context);
}

// states::TOptState states::End::process(const CoolEvent& Event)
// {
	// return Start(m_Context);
// }
