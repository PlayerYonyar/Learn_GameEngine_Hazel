#pragma once

#include "hzpch.h"//prcompiled header(预编译头文件)

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

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in Client
	Application* CreateApplication();

}




