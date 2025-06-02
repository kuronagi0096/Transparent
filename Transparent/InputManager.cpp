#include "pch.h"
#include "InputManager.h"
#include "KeyboardButton.h"
#include "ControllerButton.h"

namespace Input {
	InputManager::InputManager() {
		_actions[InputActionType::Jump] = InputAction();
		_actions[InputActionType::MoveLeft] = InputAction();
		_actions[InputActionType::MoveRight] = InputAction();
	}
	InputAction& InputManager::GetAction(InputActionType actionType) {
		return _actions.at(actionType);
	}

	void InputManager::BindKeyboard(InputActionType type, SDL_Scancode key) {
		_actions[type].AddBinding(std::make_unique<KeyboardButton>(key));
	}
	void InputManager::BindController(InputActionType type, SDL_GameController* controller, SDL_GameControllerButton button) {
		_actions[type].AddBinding(std::make_unique<ControllerButton>(controller, button));
	}
}