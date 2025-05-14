#pragma once
#include <variant>

#include "../CoroDefs.h"

namespace v3
{
namespace event
{
struct HitByMonster
{
	Coro::push_type& Yield;
	unsigned int forcePoints_ {0};
};

struct Heal
{
	unsigned int points_ {0};
};

struct Restart
{
	unsigned int startHealth_ {0};
};
}

using PossibleEvent = std::variant<event::HitByMonster, event::Heal, event::Restart>;
}