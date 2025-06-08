#pragma once
#include "SceneType.h"
#include "SceneBase.h"

class SceneManager
{
public:
	void ChangeScene(SceneType newScene);
	void Update();
	void Render();

private:
	std::unique_ptr<SceneBase> _currentScene;
};

