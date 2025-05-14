cmake_minimum_required(VERSION 3.31)
project(boost_test)
set(CMAKE_CXX_STANDARD 20)

#find_package(libassert)
find_package(Boost)
find_package(hfsm2)


add_executable(boost_test main.cpp
        Fsm/FSM.h
        Fsm/FSM_Using_Variants.cpp
        Fsm/States.h
        Fsm/FSMStateTransitions.h
        CoroDefs.h
        Fsm/FSMStateTransitions.cpp
        Fsm/States.cpp
        Fsm/TBaseState.cpp
        Fsm/TBaseState.h
        Fsm/StartState.cpp
        Fsm/StartState.h
        Fsm/EndState.cpp
        Fsm/EndState.h
        Fsm2/CurrentStateVariant.h
        Fsm2/EventsTypes.h
        Fsm2/GameOverEvents.cpp
        Fsm2/GameOverEvents.h
        Fsm2/PlayerAliveEvents.cpp
        Fsm2/PlayerAliveEvents.h
        Fsm2/PlayerDeadEvents.cpp
        Fsm2/PlayerDeadEvents.h
        Fsm2/States.h
        Fsm2/V2.cpp
        Fsm2/V2.h)

target_link_libraries(boost_test PRIVATE #[[libassert::assert]] Boost::coroutine hfsm2::hfsm2)
