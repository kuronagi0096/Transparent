#pragma once
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
private:
	State _state;

};

