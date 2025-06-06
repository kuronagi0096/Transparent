#include "pch.h"
#include <fstream>
#include "json.hpp"
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

	void InputManager::Update() {
		for (auto& pair : _actions) {
			auto& action = pair.second;
			action.Update();
		}
	}

	void InputManager::SaveBindings(const std::string& path) {
		MyJson::JsonObject root;

		for (const auto& [type, action] : _actions) {
			MyJson::JsonArray bindingsArray;
			for (const auto& binding : action.GetBindings()) {
				MyJson::JsonObject entry;
				if (auto* kb = dynamic_cast<const KeyboardButton*>(binding.get())) {
					entry["type"] = "keyboard";
					entry["key"] = static_cast<int>(kb->GetKey());
				}
				else if (auto* cb = dynamic_cast<const ControllerButton*>(binding.get())) {
					entry["type"] = "controller";
					entry["button"] = static_cast<int>(cb->GetButton());
				}
				bindingsArray.push_back(entry);
			}

			std::string key = std::to_string(static_cast<int>(type));
			root[key] = bindingsArray;
		}

		MyJson::SaveJsonToFile(root, path);
	}

	void InputManager::LoadBindings(const std::string& path) {
		auto root = MyJson::LoadJsonFromFile(path);
		if (!root.IsObject()) {
			throw std::runtime_error("Invalid JSON format for input bindings");
		}
		for (const auto& [keyStr, val] : root.AsObject()) {
			int typeInt = std::stoi(keyStr);
			InputActionType type = static_cast<InputActionType>(typeInt);

			if (!val.IsArray()) continue;
			for (const auto& entry : val.AsArray()) {
				if (!entry.IsObject()) continue;
				const auto& obj = entry.AsObject();
				std::string inputType = obj.at("type").AsString();

				if (inputType == "keyboard") {
					int keycode = obj.at("key").AsInt();
					BindKeyboard(type, static_cast<SDL_Scancode>(keycode));
				}
				else if (inputType == "controller") {
					int btn = obj.at("button").AsInt();
					SDL_GameController* controller = SDL_GameControllerOpen(0);
					if (controller) {
						BindController(type, controller, static_cast<SDL_GameControllerButton>(btn));
					}	
				}
			}
		}
	}
}