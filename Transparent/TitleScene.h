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
	class Actor* _logoActor = nullptr; // Actor for the logo
};

