#pragma once
#include "IInputSource.h"

namespace Input {
	class KeyboardButton :
		public IInputSource
	{
	public:
		explicit KeyboardButton(SDL_Scancode key);
		void Update() override;
		bool WasPressed() override;
		bool IsPressed() override;
		bool WasReleased() override;
		SDL_Scancode GetKey() const;

	private:
		SDL_Scancode _key;
		bool _wasPressed = false;
		bool _isPressed = false;
		bool _wasReleased = false;
	};
}