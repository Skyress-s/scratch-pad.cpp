#pragma once
#include <format>
#include <iostream>
#include <variant>

#include "CurrentStateVariant.h"
#include "EventsTypes.h"
#include "GameOverEvents.h"
#include "PlayerAliveEvents.h"
#include "PlayerDeadEvents.h"

namespace helper
{
    template <class... Ts>
    struct overload : Ts...
    {
        using Ts::operator()...;
    };

    //template<class... Ts> overload(Ts...)->overload<Ts...>; // no need in C++20, MSVC?
}


CurrentStateVariant onEvent(const auto& a, const auto& b)
{
    return a;
    throw std::logic_error{"Unsupported state transition"};
}

class GameStateMachine
{
public:
    void startGame(unsigned int health, unsigned int lives)
    {
        state_ = state::PlayerAlive{health, lives};
    }

    void processEvent(const PossibleEvent& event)
    {
        // state_ = std::visit(helper::overload{
        // [](const auto& state, const auto& evt) {
        // return onEvent(state, evt);
        // }
        // },
        // state_, event);

        state_ = std::visit([&](auto& state, auto& Event)
        {
            return onEvent(state, Event);
        }, state_, event);
    }

    void reportCurrentState()
    {
        std::visit(
            helper::overload{
                [](const state::PlayerAlive& alive)
                {
                    std::cout << std::format("PlayerAlive {} remaining lives {}\n", alive.health_, alive.remainingLives_);
                },
                [](const state::PlayerDead& dead)
                {
                    std::cout << std::format("PlayerDead, remaining lives {}\n", dead.remainingLives_);
                },
                [](const state::GameOver& over)
                {
                    std::cout << std::format("GameOver\n");
                }
            },
            state_);
    }

private:
    CurrentStateVariant state_;
};

inline void GameHealthFSMTest()
{
    std::cout << std::format("sizeof(HealthState):   {}\n", sizeof(CurrentStateVariant));
    std::cout << std::format("sizeof(PossibleEvent): {}\n", sizeof(PossibleEvent));

    GameStateMachine game;
    game.startGame(100, 1);

    try
    {
        // game.processEvent(event::HitByMonster{30});
        // game.reportCurrentState();
        // game.processEvent(event::HitByMonster{30});
        // game.reportCurrentState();
        // game.processEvent(event::HitByMonster{30});
        // game.reportCurrentState();
        // game.processEvent(event::HitByMonster{30});
        // game.reportCurrentState();
        // game.processEvent(event::Restart{100});
        // game.reportCurrentState();
        // game.processEvent(event::HitByMonster{60});
        // game.reportCurrentState();
        // game.processEvent(event::HitByMonster{50});
        // game.reportCurrentState();
        // game.processEvent(event::Restart{100});
        // game.reportCurrentState();
    }
    catch (std::exception& ex)
    {
        std::cout << "Exception! " << ex.what() << '\n';
    }
}
