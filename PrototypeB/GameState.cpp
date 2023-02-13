#include "GameState.h"

GameWindow::GameWindow(int height, int weigth, unsigned short fps)
{
	this->height     = height;
	this->weigth     = weigth;
	this->target_fps = fps;

	this->should_run = true;

	std::cout << "Game Window was create succesfully!\n";
}

GameWindow::~GameWindow()
{
	// TODO: Done with that
}

void GameWindow::run()
{
#pragma region Initializing GameState
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
		std::cout << "Initialize Error: " << SDL_GetError() << std::endl;

	window = SDL_CreateWindow("PROTOTYPE.B", 100, 100, this->weigth, this->height, SDL_WINDOW_SHOWN);
	if (window == nullptr)
		std::cout << "Initializing Window Error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
		std::cout << "Initializing Renderer Error: " << SDL_GetError() << std::endl;

#pragma endregion
#pragma region Rendering
	while (should_run)
	{
		render();
	}
#pragma endregion
}

void GameWindow::render()
{
	SDL_RenderClear(this->renderer);

	SDL_RenderPresent(this->renderer);
}