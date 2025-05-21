#pragma once
#include "pch.h"

class Signal
{
public:
	void Connect(const std::function<void()>& slot);
	void Emit();
private:
	std::vector<std::function<void()>> _slots;
};

