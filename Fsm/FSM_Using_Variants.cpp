

// #include <chrono>
// #include <iostream>

// #include "FSMStateTransitions.h"
// #include "States.h"

// int main()
// {
//
//     fsm_state_transitions::FSM Fsm {};
//
//     UpdateEvent ReusableUpdateEvent("onufTunrftunununtnntntntdnrdnrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr");
//     auto Start = std::chrono::high_resolution_clock::now();
//     for (int i = 0; i < 1000; ++i)
//     {
//         std::cout << "Current State: " << Fsm.getState() << std::endl;
//         Fsm.process(ReusableUpdateEvent);
//     }
//     auto End = std::chrono::high_resolution_clock::now();
//
//     std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(End - Start) << "\n";
//
//     return 0;
// }
