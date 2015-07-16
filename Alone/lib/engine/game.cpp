#include "game.h"

Game::Game()
{
	this->mainWindow = NULL;
	this->mainSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	this->mainWindow = SDL_CreateWindow(
		"Alone",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1280,
		720,
		SDL_WINDOW_SHOWN
	);

	if (this->mainWindow == NULL) {
		printf("Window could not be reated SDL_Error: %s\n", SDL_GetError());
		this->crashGame();
	}

	// set to fullscreen windowed
	//SDL_SetWindowFullscreen(this->mainWindow, 0);
	this->mainSurface = SDL_GetWindowSurface(this->mainWindow);
	
	inputManager *ctrl = new inputManager();
	this->inputController = ctrl;

	//Get window surface
	SDL_Surface *screenSurface = SDL_GetWindowSurface(this->mainWindow);

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

	//Update the surface
	SDL_UpdateWindowSurface(this->mainWindow);
}

void Game::handleInput(const Uint8* keys) {
	if (keys[SDL_SCANCODE_ESCAPE]) {
		this->gameRunning = false;
	}
}

Game::~Game()
{
}

void Game::crashGame() {
	SDL_DestroyWindow(this->mainWindow);
	SDL_Quit();
}

void Game::render() {}
void Game::step() {}