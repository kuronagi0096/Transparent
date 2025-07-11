#include "pch.h"
#include <iostream>
#include "Game.h"



int WinMain(int argc, char* argv[]) {
	printf("Starting Transparent Game...\n");
	Game& game = Game::GetInstance();
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}