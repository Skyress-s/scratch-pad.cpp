#pragma once

#include <iostream>
#include <format>
#include "CurrentStateVariant.h"
#include "EventsTypes.h"

inline CurrentStateVariant onEvent(const state::PlayerAlive& alive, const event::HitByMonster& monster) {
	std::cout << std::format("PlayerAlive -> HitByMonster force {}\n", monster.forcePoints_);
	if (alive.health_ > monster.forcePoints_)
	{
		return state::PlayerAlive{ alive.health_ - monster.forcePoints_, alive.remainingLives_ };
	}

	if (alive.remainingLives_ > 0)
		return state::PlayerDead{ alive.remainingLives_ - 1 };

	return state::GameOver{};
}

inline CurrentStateVariant onEvent(const state::PlayerAlive& alive, const event::Heal& healingBonus) {
	std::cout << std::format("PlayerAlive -> Heal points {}\n", healingBonus.points_);

	return state::PlayerAlive{ alive.health_ + healingBonus.points_, alive.remainingLives_ };;
}
