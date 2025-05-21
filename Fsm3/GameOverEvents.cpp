#include "GameOverEvents.h"

v3::CurrentStateVariant v3::onEvent(const state::GameOver& over, const event::Restart& restart)
{
	std::cout << std::format("GameOver -> restart\n");

	std::cout << "Game Over, please restart the whole game!\n";

	return over;
}
