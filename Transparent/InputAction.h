#pragma once
#include "pch.h"
#include <SDL.h>
#include "IInputSource.h"

namespace Input {
	class InputAction
	{
	public:
		void AddBinding(std::unique_ptr<IInputSource> source);
		void Update();
		bool WasPressed() const;
		bool IsPressed() const;
		bool WasReleased() const;
		const std::vector<std::unique_ptr<IInputSource>>& GetBindings() const;

	private:
		std::vector<std::unique_ptr<IInputSource>> _bindings;
		bool _wasPressed = false;
		bool _isPressed = false;
		bool _wasReleased = false;
	};
}
