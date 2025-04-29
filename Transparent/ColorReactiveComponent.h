#pragma once
#include "Component.h"
#include "IColorObserver.h"
#include "WorldColor.h"

class ColorReactiveComponent
	: public Component, public IColorObserver
{
public:
	ColorReactiveComponent(Actor* owner);
	virtual ~ColorReactiveComponent();

	void OnWorldColorChanged(WorldColor color) override;

private:
	void UpdateAppearance(WorldColor color);
};

