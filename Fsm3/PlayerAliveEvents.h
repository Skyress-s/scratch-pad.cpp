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

CurrentStateVariant onEvent(const state::PlayerAlive& alive, const event::HitByMonster& monster);

inline CurrentStateVariant onEvent(const state::PlayerAlive& alive, const event::Heal& healingBonus) {
	std::cout << std::format("PlayerAlive -> Heal points {}\n", healingBonus.points_);

	return state::PlayerAlive{ alive.health_ + healingBonus.points_, alive.remainingLives_ };;
}
}
