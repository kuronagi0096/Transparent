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