#pragma once
#include <variant>
#include "States.h"

namespace v3
{


using CurrentStateVariant = std::variant<state::PlayerAlive, state::PlayerDead, state::GameOver>;
}
