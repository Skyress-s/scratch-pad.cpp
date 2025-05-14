#pragma once

#include <iostream>
#include <format>
#include "CurrentStateVariant.h"
#include "EventsTypes.h"
namespace v3
{


class Alive
{
};

inline CurrentStateVariant onEvent(const state::PlayerAlive& alive, const event::HitByMonster& monster) {
	monster.Yield("Got hit by monster");
	std::cout << std::format("PlayerAlive -> HitByMonster force {}\n", monster.forcePoints_);
	if (alive.health_ > monster.forcePoints_)
	{
		return state::PlayerAlive{ alive.health_ - monster.forcePoints_, alive.remainingLives_ };
	}

	if (alive.remainingLives_ > 0)
		return state::GameOver{};

	return alive;
}

inline CurrentStateVariant onEvent(const state::PlayerAlive& alive, const event::Heal& healingBonus) {
	std::cout << std::format("PlayerAlive -> Heal points {}\n", healingBonus.points_);

	return state::PlayerAlive{ alive.health_ + healingBonus.points_, alive.remainingLives_ };;
}
}
