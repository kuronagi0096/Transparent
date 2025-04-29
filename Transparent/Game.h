#pragma once
#include <SDL.h>
#include <vector>

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* _window;
	bool _isRunning;
	Uint32 _ticksCount;

	SDL_Renderer* _renderer;
	std::vector<class Actor*> _actors;
	std::vector<class Actor*> _pendingActors;
};

