#pragma once
#include "IInputSource.h"

namespace Input {
class ControllerButton :
    public IInputSource
{
public:
    ControllerButton(SDL_GameController* controller, SDL_GameControllerButton button);
	void Update() override;
	bool WasPressed() override;
	bool IsPressed() override;
	bool WasReleased() override;
	SDL_GameControllerButton GetButton() const;

private:
	SDL_GameController* _controller;
	SDL_GameControllerButton _button;
	bool _wasPressed = false;
	bool _isPressed = false;
	bool _wasReleased = false;
};
}
