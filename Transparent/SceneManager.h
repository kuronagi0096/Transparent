#pragma once
#include "SceneType.h"
#include "SceneBase.h"
#include "Singleton.h"

class SceneManager
	: public Singleton<SceneManager>
{
	friend class Singleton<SceneManager>;
public:
	void ChangeScene(SceneType newScene);
	void Update();
	void Render();

private:
	std::unique_ptr<SceneBase> _currentScene;
};

