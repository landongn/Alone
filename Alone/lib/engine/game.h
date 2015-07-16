#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include "input.h"

class Game
{
public:
	Game();
	~Game();
	SDL_Window *mainWindow;
	SDL_Surface *mainSurface;
	inputManager *inputController;
	bool gameRunning = false;
	bool hasInitialized;

	void crashGame();
	void handleInput(const Uint8* keys);
	void step();
	void render();
	
	
private:
	
};