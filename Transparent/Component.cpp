#include "Component.h"
#include "pch.h"

Component::Component(Actor* owner, int updateOrder)
	: _owner(owner), _updateOrder(updateOrder), _isEnabled(true)
{
	if (_owner)
	{
		_owner->AddComponent(this);
	}
}
void Component::SetEnabled(bool enabled)
{
	_isEnabled = enabled;
}