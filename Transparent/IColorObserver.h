#pragma once
#include "WorldColor.h";
class IColorObserver {
public:
	virtual void OnWorldColorChanged(WorldColor color);
	virtual ~IColorObserver() = default;
};

