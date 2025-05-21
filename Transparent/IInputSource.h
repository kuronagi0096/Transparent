#pragma once
class IInputSource
{
public:
	virtual ~IInputSource() = default;

	virtual void Update() = 0;
};

