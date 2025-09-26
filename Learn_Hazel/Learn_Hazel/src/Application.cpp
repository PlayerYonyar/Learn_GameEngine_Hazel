//Application.cpp:
#include "hzpch.h"//prcompiled header(预编译头文件)

#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"
namespace Hazel
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run() 
	{

		WindowResizeEvent e(1280, 720);
		HZ_TRACE("{}", e.ToString());
		//HZ_TRACE(e); //使用HZ_TRACE宏记录事件


		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_TRACE("{}", e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_TRACE("{}", e.ToString());
		}

		while (true) 
		{ 
			//printf("Hello Learn Hazel !\nHazel Engine is being updated !"); 
		};
	}
}

