#include <stdio.h>
#include "lib/engine/game.h"

int main(int argc, char **argv) {
	Game *gameLoop = new Game();

	while (!gameLoop->gameRunning) {
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		gameLoop->handleInput(currentKeyStates);
		gameLoop->step();
		gameLoop->render();
	}
	return 0;
}