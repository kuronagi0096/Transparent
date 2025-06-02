#include "pch.h"
#include "KeyboardButton.h"

namespace Input {
	KeyboardButton::KeyboardButton(SDL_Scancode key) : _key(key) {}

	void KeyboardButton::Update() {
		const Uint8* state = SDL_GetKeyboardState(nullptr);
		bool currently = state[_key];
		_wasPressed = !_isPressed && currently;
		_isPressed = currently;
		_wasReleased = _isPressed && !currently;
	}

	bool KeyboardButton::WasPressed() {
		return _wasPressed;
	}
	bool KeyboardButton::IsPressed() {
		return _isPressed;
	}
	bool KeyboardButton::WasReleased() {
		return _wasReleased;
	}
	SDL_Scancode KeyboardButton::GetKey() const {
		return _key;
	}
}