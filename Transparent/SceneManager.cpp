#include "pch.h"
#include "SceneManager.h"
#include "TitleScene.h"

void SceneManager::ChangeScene(SceneType newScene) {
	switch (newScene) {
	case SceneType::Title:
		_currentScene = std::make_unique<TitleScene>();
		break;
	case SceneType::InGame:
		// _currentScene = std::make_unique<InGameScene>(); // Assuming InGameScene is defined similarly
		break;
	default:
		throw std::runtime_error("Unknown scene type");
	}
}

void SceneManager::Update() {
	if (_currentScene) {
		_currentScene->Update();
	}
}

void SceneManager::Render() {
	if (_currentScene) {
		_currentScene->Render();
	}
}
