//Application.cpp:
#include "hzpch.h"//prcompiled header(预编译头文件)

#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
#define BIND_EVENT_FN(x) std::bind(&x,this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));//m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		HZ_CORE_INFO("{0}",e.ToString());
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

		while (m_Running)
		{ 
			//printf("Hello Learn Hazel !\nHazel Engine is being updated !"); 
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		};
	}
}

