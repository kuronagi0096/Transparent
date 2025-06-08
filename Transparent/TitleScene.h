#pragma once
#include "SceneBase.h"
class TitleScene :
    public SceneBase
{
public:
    TitleScene();
	void Update() override;
	void Render() override;
private:
	std::vector<std::unique_ptr<Actor>> _actors;
};

