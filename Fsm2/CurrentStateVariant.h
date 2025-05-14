#pragma once

#include <variant>
#include "States.h"

using CurrentStateVariant = std::variant<state::PlayerAlive, state::PlayerDead, state::GameOver>;
