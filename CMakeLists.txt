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
        Fsm/FSMStateTransitions.cpp)

target_link_libraries(boost_test PRIVATE #[[libassert::assert]] Boost::coroutine hfsm2::hfsm2)
