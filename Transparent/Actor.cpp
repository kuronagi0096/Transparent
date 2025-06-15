#include "Actor.h"
#include "pch.h"

void Actor::Update(float deltaTime)
{
	if (_state == Active)
	{
		UpdateActor(deltaTime);
		UpdateComponents(deltaTime);
	}
}
void Actor::UpdateComponents(float deltaTime)
{
	for (auto& component : _components)
	{
		component->UpdateComponent(deltaTime);
	}
}
void Actor::AddComponent(Component* component)
{
	if (component)
	{
		_components.push_back(component);
	}
}
void Actor::RemoveComponent(Component* component)
{
	auto it = std::remove(_components.begin(), _components.end(), component);
	if (it != _components.end())
	{
		_components.erase(it, _components.end());
	}
}