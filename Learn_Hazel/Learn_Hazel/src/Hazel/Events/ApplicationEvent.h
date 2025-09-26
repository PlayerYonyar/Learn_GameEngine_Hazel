//ApplocationEvent.h:
#pragma once
#include "hzpch.h"//prcompiled header(预编译头文件)
#include "Event.h"

//#include <sstream>

namespace Hazel
{
	class HAZEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {}

		inline unsigned GetWidth() const { return m_Width; } //获取宽度
		inline unsigned GetHeight() const { return m_Height; } //获取高度
		//重写ToString函数，返回事件的字符串表示
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};
	class HAZEL_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	//更新，渲染和时钟函数以事件的形式传播，但如果考究，我们应该将它作为一个事件来实现
	//但因为它们是硬件的固有特性，所以，我觉得应该是硬编码的
	class HAZEL_API AppTickEvent :public Event
	{
		public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	
	class HAZEL_API AppUpdateEvent :public Event
	{
		public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	class HAZEL_API AppRenderEvent :public Event
	{
		public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};




}