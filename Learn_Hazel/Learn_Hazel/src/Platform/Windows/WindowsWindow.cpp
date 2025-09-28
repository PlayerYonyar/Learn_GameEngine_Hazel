//WindowsWindow.cpp
#include "hzpch.h"//预编译头文件
#include "WindowsWindow.h"

//#include "Hazel/Events/ApplicationEvent.h"
//#include "Hazel/Events/MouseEvent.h"
//#include "Hazel/Events/KeyEvent.h"
//#include <Glad/glad.h>
//#include <GLFW/glfw3.h>

namespace Hazel
{
	static bool s_GLFWInitialized = false;

	//static void GLFWErrorCallback(int error, const char* description)
	//{
	//	HZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	//}
	//为什么这个不用lambda，而是写在外面;我觉得这里不用lambda 写在外面是为了写成static func


	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	/*
		bool WindowsWindow::IsVSync() const
	{
		return false;
	}
	*/

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HZ_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		if (!s_GLFWInitialized)
		{
			//TODO:glfwTerminate on sydtem shutdown
			int success = glfwInit();
			HZ_CORE_ASSERT(success, "Could not initialize GLFW!");
			//HZ_CORE_ASSERT(glfwInit(), "Could not initialize GLFW!");
			//glfwSetErrorCallback(GLFWErrorCallback);
			/*
			glfwSetErrorCallback([](int error, const char* description) {
				HZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
				});
			*/
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);

		/*
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			Event event; // Create an event object
			// Populate the event object with key information
			// For example: event.Key = key; event.Action = action;
			data.EventCallback(event); // Call the event callback
			});
		*/

		//int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//HZ_CORE_ASSERT(status, "Failed to initialize Glad!")
		
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		/*
		//Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowResizeEvent event(width, height); // Create a resize event
			data.EventCallback(event); // Call the event callback

			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event; // Create a close event
				data.EventCallback(event); // Call the event callback
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				//因为这个KeyCode是GLFW的，所以我们需要将它转换为Hazel的KeyCode,以便跨平台兼容
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0); // Create a key pressed event
					data.EventCallback(event); // Call the event callback
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key); // Create a key released event
					data.EventCallback(event); // Call the event callback
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1); // Create a key pressed event with repeat count
					data.EventCallback(event); // Call the event callback
					break;
				}
				}
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				KeyTypedEvent event(keycode);
				data.EventCallback(event); // Call the event callback

			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button); // Create a mouse button pressed event
					data.EventCallback(event); // Call the event callback
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button); // Create a mouse button released event
					data.EventCallback(event); // Call the event callback
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xOffset, (float)yOffset); // Create a mouse scrolled event
				data.EventCallback(event); // Call the event callback
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)xPos, (float)yPos); // Create a mouse moved event
				data.EventCallback(event); // Call the event callback
			});
		*/
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
		/*
		Event event;
		m_Data.EventCallback(event); // Call the event callback
		HZ_CORE_TRACE("Window updated");
		*/
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
			//m_Data.VSync = true;
		}
		else
		{
			glfwSwapInterval(0);
			//m_Data.VSync = false;
		}
		m_Data.VSync = enabled;
		//HZ_CORE_INFO("VSync is {0}", m_Data.VSync ? "enabled" : "disabled");
	}
	//检查垂直同步是否开启
	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
