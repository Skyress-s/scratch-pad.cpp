#pragma once

#include <format>
#include <iostream>

#include "CurrentStateVariant.h"
#include "EventsTypes.h"
namespace v3
{
CurrentStateVariant onEvent(const state::GameOver& over, const event::Restart& restart);
}
