#pragma once

namespace state {
	struct PlayerAlive { unsigned int health_{ 0 }; unsigned int remainingLives_{ 0 }; };

	struct PlayerDead { unsigned int remainingLives_{ 0 }; };

	struct GameOver { };
}
