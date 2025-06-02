#include "pch.h"
#include "ControllerButton.h"

namespace Input {
	ControllerButton::ControllerButton(SDL_GameController* controller, SDL_GameControllerButton button)
		: _controller(controller), _button(button) {
	}
	void ControllerButton::Update() {
		if (!_controller) return;
		bool currently = SDL_GameControllerGetButton(_controller, _button);
		_wasPressed = !_isPressed && currently;
		_isPressed = currently;
		_wasReleased = _isPressed && !currently;
	}
	bool ControllerButton::WasPressed() {
		return _wasPressed;
	}
	bool ControllerButton::IsPressed() {
		return _isPressed;
	}
	bool ControllerButton::WasReleased() {
		return _wasReleased;
	}
	SDL_GameControllerButton ControllerButton::GetButton() const {
		return _button;
	}
}