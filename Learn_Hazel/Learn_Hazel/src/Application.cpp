//Application.cpp:
#include "hzpch.h"//prcompiled header(预编译头文件)

#include "Application.h"


#include "Hazel/Log.h"

#include <glad/glad.h>
//#include <GLFW/glfw3.h>因为:在`--Hazel-defines:` 中添加 ` "GLFW_INCLUDE_NONE", `->这样可以省去 在`WindowsWindow.cpp`中 添加 `#include <GLFW/glfw3.h>` -> 只需一个 `#include <glad/glad.h>`


namespace Hazel
{
#define BIND_EVENT_FN(x) std::bind(&x,this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));//m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		
		//unsigned id;
		//glGenVertexArrays(1, &id);
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		//调度器调度，模板匹配
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));//处理窗口关闭事件


		//HZ_CORE_INFO("{0}",e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			//如果标记为已处理,就退出
			if (e.m_Handled)
			{
				break;
			}

		}
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
			
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		};
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false; //设置运行状态为false，退出应用程序
		return true; //返回true表示事件已被处理
	}
}

