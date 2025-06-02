#pragma once

namespace Input {
	class IInputSource
	{
	public:
		virtual ~IInputSource() = default;

		virtual void Update() = 0;
		virtual bool WasPressed() = 0;
		virtual bool IsPressed() = 0;
		virtual bool WasReleased() = 0;
	};
}
