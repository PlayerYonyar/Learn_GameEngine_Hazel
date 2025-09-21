#pragma once

#include "src/Hazel/Core.h"	
namespace Hazel
{
	class __declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

}




