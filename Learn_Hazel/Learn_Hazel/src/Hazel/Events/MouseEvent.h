//MosuseEvent.h:
#pragma once
//#include "hzpch.h"//预编译头文件
#include "Event.h"

#include <sstream>

/*编程规范：
公开的先写，
私有的后写
*/
namespace Hazel
{
	class HAZEL_API MouseMovedEvent :public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			:m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; } //获取鼠标X坐标
		inline float GetY() const { return m_MouseY; } //获取鼠标Y坐标
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY; //鼠标X和Y坐标
	};

	class HAZEL_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {
		}
		inline float GetXOffset() const { return m_XOffset; } //获取鼠标滚轮X偏移
		inline float GetYOffset() const { return m_YOffset; } //获取鼠标滚轮Y偏移
		//std::string ToString() const override
		//{
		//	std::stringstream ss;
		//	ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
		//	return ss.str();
		//}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset; //鼠标滚轮X和Y偏移
	};

	class HAZEL_API MouseButtonEvent : public Event
	{
		public:
		inline int GetMouseButton() const { return m_Button; } //获取鼠标按钮
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput) //事件类别
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {} //构造函数，初始化鼠标按钮
		int m_Button; //鼠标按钮
	};
	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
		public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {} //构造函数，初始化鼠标按钮
		EVENT_CLASS_TYPE(MouseButtonPressed) //事件类型
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
	};
	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
		public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {} //构造函数，初始化鼠标按钮
		EVENT_CLASS_TYPE(MouseButtonReleased) //事件类型
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
	};
}