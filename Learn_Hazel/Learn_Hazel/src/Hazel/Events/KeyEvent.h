//KeyEvent.h:
#pragma once
//#include "hzpch.h"//预编译头文件
#include "Event.h"

#include <sstream>

namespace Hazel
{
	class HAZEL_API KeyEvent :public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; } //获取按键代码

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)



	protected://受保护的构建函数
		KeyEvent(int keycode)
			:m_KeyCode(keycode) {}

		int m_KeyCode; //按键代码
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			:KeyEvent(keycode), m_RepeatCount(repeatCount) {
		}
		inline int GetRepeatCount() const { return m_RepeatCount; } //获取重复次数
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		//static EventType GetStaticType() { return EventType::KeyPressed; }\
		//	virtual EventType GetEventType() const override { return GetStaticType(); }\
		//	virtual const char* GetName() const override { return "KeyPressed"; }

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;//重复次数
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};

	class HAZEL_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};


}