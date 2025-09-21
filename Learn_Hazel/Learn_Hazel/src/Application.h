#pragma once
#include<stdio.h>	
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




