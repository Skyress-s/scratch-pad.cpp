#pragma once
#include <format>
#include <iostream>

#include "CurrentStateVariant.h"
#include "EventsTypes.h"


inline CurrentStateVariant onEvent(const state::PlayerDead& dead, const event::Restart& restart) {
	std::cout << std::format("PlayerDead -> restart\n");

	return state::PlayerAlive{ restart.startHealth_, dead.remainingLives_ };
}

