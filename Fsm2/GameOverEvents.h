#pragma once

#include <format>
#include <iostream>

#include "CurrentStateVariant.h"
#include "EventsTypes.h"

inline CurrentStateVariant onEvent(const state::GameOver& over, const event::Restart& restart) {
	std::cout << std::format("GameOver -> restart\n");

	std::cout << "Game Over, please restart the whole game!\n";

	return over;
}
