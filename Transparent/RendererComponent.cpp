#include "pch.h"
#include "RendererComponent.h"
#include "TransformComponent.h"

RendererComponent::RendererComponent(Actor* owner, const std::string& imagePath, int updateOrder)
	: Component(owner, updateOrder)
{
	_texture = AssetManager::GetInstance().LoadTexture(imagePath);
}

void RendererComponent::Draw()
{
	if (_texture && _isEnabled)
	{
		int w, h;
		SDL_QueryTexture(_texture, nullptr, nullptr, &w, &h);

		auto transform = _owner->GetComponent<TransformComponent>();
		Vector3 pos = transform ? transform->GetPosition() : Vector3(0, 0, 0);

		SDL_Rect dstRect = {
			static_cast<int>(pos.x - w / 2),
			static_cast<int>(pos.y - h / 2),
			w,
			h
		};
		SDL_RenderCopy(AssetManager::GetInstance().GetRenderer(), _texture, nullptr, &dstRect);
	}
}