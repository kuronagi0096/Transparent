#include "Game.h"
#include "SDL.h"

Game::Game() {
	_isRunning = true;
	_window = nullptr;
	_renderer = nullptr;
}
bool Game::Initialize() {
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	_window = SDL_CreateWindow(
		"Transparent",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1920,
		1080,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	);
	if (!_window)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	_renderer = SDL_CreateRenderer(
		_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
}
void Game::Shutdown() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
void Game::RunLoop() {
	while (_isRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_isRunning = false;
			break;
		default:
			break;
		}
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE])
	{
		_isRunning = false;
	}
}
void Game::UpdateGame() {
	// Update game logic here
	float deltaTime = (SDL_GetTicks() - _ticksCount) / 1000.0f;
}
void Game::GenerateOutput() {
	SDL_SetRenderDrawColor(
		_renderer,
		30,
		30,
		255,
		255
	);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}
