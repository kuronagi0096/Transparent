#include "pch.h"
#include "InputAction.h"

namespace Input {
	void InputAction::AddBinding(std::unique_ptr<IInputSource> source) {
		_bindings.emplace_back(std::move(source));
	}
	
	void InputAction::Update() {
		_wasPressed = false;
		_isPressed = false;
		_wasReleased = false;

		for (auto& b : _bindings) {
			b->Update();
			_wasPressed |= b->WasPressed();
			_isPressed |= b->IsPressed();
			_wasReleased |= b->WasReleased();
		}
	}

	bool InputAction::WasPressed() const {
		return _wasPressed;
	}
	bool InputAction::IsPressed() const {
		return _isPressed;
	}
	bool InputAction::WasReleased() const {
		return _wasReleased;
	}
	const std::vector<std::unique_ptr<IInputSource>>& InputAction::GetBindings() const {
		return _bindings;
	}
}