//Window.h:
#pragma once
#include "hzpch.h"//预编译头文件
#include "Core.h"
#include "Events/Event.h"

namespace Hazel
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		//构造函数，提供默认参数
		// 可以在创建窗口时指定标题、宽度和高度
		WindowProps(const std::string& title = "Hazel Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	//窗口接口
	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		//虚函数，纯虚函数
		virtual void OnUpdate() = 0;
		//获取窗口的宽度和高度
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		//Window attributes: 窗口属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		//取决于在哪个平台上运行
		//virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());//Create 必须在每个平台上实现
		//virtual void* GetNativeWindow() const = 0;
	};
}
