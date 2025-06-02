#pragma once
#include "pch.h"
#include <unordered_map>
#include "InputAction.h"
#include "InputActionType.h"

namespace Input {
	class InputManager
	{
	public:
		InputAction& GetAction(InputActionType actionType);
		
		void BindKeyboard(InputAction& action, SDL_Scancode key);
		void BindController(InputAction& action, SDL_GameController* controller, SDL_GameControllerButton button);
		void Update();
		void SaveBindings(const std::string& path);
		void LoadBindings(const std::string& path);

	private:
		std::unordered_map<InputActionType, InputAction> _actions;
	};
}