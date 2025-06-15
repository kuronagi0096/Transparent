#pragma once
#include "Component.h"
#include "pch.h"
#include "AssetManager.h"
class RendererComponent :
    public Component
{
public:
	RendererComponent(Actor* owner, const std::string& imagePath, int updateOrder = 100);
	virtual ~RendererComponent() = default;

	virtual void Draw();

protected:
	SDL_Texture* _texture = nullptr;
};

