#pragma once
#include "Component.h"
class TransformComponent :
    public Component
{
public:
    TransformComponent(Actor* owner, int updateOrder = 10);
    void SetPosition(Vector3 position);
	Vector3 GetPosition() const;

private:
	Vector3 _position; // Position of the actor in 3D space
	Vector3 _scale;    // Scale of the actor
	float _rotation;   // Rotation of the actor in radians
};

