#pragma once

#include "hzpch.h"//prcompiled header(预编译头文件)

//#include<stdio.h>	

#include "Hazel/Core.h"	
namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();

}




