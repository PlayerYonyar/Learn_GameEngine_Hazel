//Core.h:
#pragma once
#include "hzpch.h"//预编译头文件
#ifdef HZ_PLATFORM_WINDOWS
#ifdef HZ_BUILD_DLL
#define HAZEL_API __declspec(dllexport)
#else
#define HAZEL_API __declspec(dllimport)
#endif
#else
#error Hazel only supports Windows!
#endif


#ifdef HZ_ENABLE_ASSERTS
	 // 如果 x 为假，则触发断言
#define HZ_ASSERT(x, ...) {if(!(x)) { HZ_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); }} // __debugbreak() 为 VS 的断点函数，其他平台无效
#define HZ_CORE_ASSERT(x, ...) {if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); }} // __debugbreak() 为 VS 的断点函数，其他平台无效

#else
#define HZ_ASSERT(x, ...)
#define HZ_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 <<x)

//#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
