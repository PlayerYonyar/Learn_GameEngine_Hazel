#pragma once
#include "hzpch.h"//prcompiled header(预编译头文件)


#ifdef HZ_PLATFORM_WINDOWS
#ifdef HZ_BUILD_DLL
	#define HAZEL_API __declspec(dllexport)
#else
	#define HAZEL_API __declspec(dllimport)
#endif
#else
	#error Hazel only supports Windows!
#endif

#define BIT(x) (1 << x)
