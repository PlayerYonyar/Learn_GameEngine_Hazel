#pragma once

//#include "hzpch.h"//prcompiled header(预编译头文件)

//#include<stdio.h>	

#include "Hazel/Core.h"	

#include "Hazel/Events/Event.h"
#include "Hazel/Window.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		std::unique_ptr<Window> m_Window; //使用智能指针管理窗口资源
		bool m_Running = true;
	};

	//To be defined in Client
	Application* CreateApplication();

}




