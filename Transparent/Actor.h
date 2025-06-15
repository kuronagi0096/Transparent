#pragma once
#include "Vector3.h"
#include <vector>
class Actor
{
public:
	enum State {
		Active,
		Paused,
		Dead
	};
	Actor(class Game* game);
	virtual ~Actor() = default;
	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
	template <typename T>
	T* GetComponent() const
	{
		static_assert(std::is_base_of<Component, T>::value, "T must be a Component type");
		for (auto& component : _components)
		{
			T* castedComponent = dynamic_cast<T*>(component);
			if (castedComponent)
			{
				return castedComponent; // Return the first matching component
			}
		}
		return nullptr; // No matching component found
	}
private:
	State _state;
	class Game* _game;
	std::vector<class Component*> _components;
};

