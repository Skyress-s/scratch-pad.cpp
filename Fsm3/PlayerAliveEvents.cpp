#include "PlayerAliveEvents.h"

v3::CurrentStateVariant v3::onEvent(const state::PlayerAlive& alive, const event::HitByMonster& monster)
{
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
