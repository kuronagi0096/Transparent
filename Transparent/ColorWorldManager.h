#pragma once
#include "WorldColor.h"
#include "IColorObserver.h"
#include <vector>

class ColorWorldManager
{
public:
	void SetColor(WorldColor color);
	WorldColor GetColor() const;

	void RegisterObserver(IColorObserver* observer);
	void UnregisterObserver(IColorObserver* observer);

private:
	WorldColor _currentColor = WorldColor::Blue;
	std::vector<IColorObserver*> _observers;

	void NotiryObservers();
};

