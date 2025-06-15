#include "pch.h"
#include "TransformComponent.h"
#include "Actor.h"

TransformComponent::TransformComponent(Actor* owner, int updateOrder)
	: Component(owner, updateOrder)
{
	_position = Vector3(0.0f, 0.0f, 0.0f); // Initialize position to origin
	_scale = Vector3(1.0f, 1.0f, 1.0f); // Initialize scale to identity
	_rotation = 0.0f; // Initialize rotation to zero
}

void TransformComponent::SetPosition(Vector3 position)
{
	_position = position;
}

Vector3 TransformComponent::GetPosition() const
{
	return _position;
}