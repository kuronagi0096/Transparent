#pragma once
#include "pch.h"
#include <memory>
#include "Actor.h"

class SceneBase
{
public:
	virtual ~SceneBase() = default;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

