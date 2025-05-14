#pragma once
#include <variant>

namespace event {
	struct HitByMonster { unsigned int forcePoints_{ 0 }; };

	struct Heal { unsigned int points_{ 0 }; };

	struct Restart { unsigned int startHealth_{ 0 }; };
}

using PossibleEvent = std::variant<event::HitByMonster, event::Heal, event::Restart>;
