//Event.h:
#pragma once
#include "hzpch.h"//prcompiled header(预编译头文件)

#include"Hazel/Core.h"

//#include <string>
//#include <functional>

namespace Hazel
{
	/*
	* Events in Hazel are currently blocking, meaning when an event occurs it
	* immediately gets dispatched and must be dealt with right then an there.
	* For the future, a better strategy might be to buffer events in an event
	* bus and process them during the "event" part of the update stage.
	Hazel中的事件目前是阻塞的，这意味着当一个事件发生时，它
	会立即被调度，并且必须立即处理。
	未来，一个更好的策略可能是将事件缓冲在一个事件总线中，
	并在更新阶段的“事件”部分处理它们。
	*/
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char* GetName() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}
	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			//如果它的类别与传入的类别相同，则返回true
			return GetCategoryFlags() & category;
		}
		bool m_Handled = false;
	protected:
		//bool m_Handled = false;
	};

	/*
	Dispatcher是一种基于事件类型调度事件的方法
	*/
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
		{
			return os << e.ToString();
	}


}