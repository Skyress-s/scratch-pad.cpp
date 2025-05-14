#include <boost/coroutine2/all.hpp>
#include <iostream>
#include <vector>

#include "CoroDefs.h"
#include "Fsm/FSMStateTransitions.h"
#include "Fsm/States.h"

#include "Fsm2/V2.h"
#include "Fsm3/V2.h"


using namespace boost::coroutines2;



// void co_increment_1(Coro::push_type& Yield, std::shared_ptr<SGameState> GameState)
// {
// 	SSharedData sd {"awdawdiga"};
// 	int CurrentVariable {0};
// 	std::cout << "Pushed 1\n";
// 	Yield(sd);
// 	bool test;
//
// 	GameState->DoSomeWork(Yield);
//
// 	co_increment_2(Yield);
//
// 	std::cout << "Pushed 2\n";
// 	Yield(sd);
// 	std::cout << "Pushed 3\n";
// }

void coro_main(Coro::push_type& Yield)
{
	v3::GameStateMachine Fsm2;
	Fsm2.startGame(30, 4);
	// fsm_state_transitions::FSM Fsm {};

	for (int i = 0; i < 100; ++i)
	{
		if (i % 4 == 0)
		{
			Fsm2.processEvent(v3::event::HitByMonster(Yield, 4));
			// Fsm.process(UpdateEvent(Yield));
		}
		else
		{
			// Fsm2.processEvent(v3::event::HitByMonster(Yield, 2));
			// Fsm.process(CoolEvent());
		}
		// Fsm2.reportCurrentState();
		// std::cout << Fsm.getState() << std::endl;
		// Yield("Message!");
	}
}

int main()
{
	Coro::pull_type Ccoro {coro_main};

	for (int i = 0; i < 2 && Ccoro; ++i)
	{

	// }
	// while (Ccoro)
	// {

		std::cout << Ccoro.get() << std::endl;
		Ccoro();
	}
}
