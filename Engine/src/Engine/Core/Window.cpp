#include "epch.h"
#include "Window.h"

// Event
#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

#include <glad/glad.h>

namespace Engine {
	// Setting GLFW Functions and Variables
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		E_API_ASSERT("GLFW Error ({0}) : {1}", error, description);
	}

	Window::~Window()
	{
		Shutdown();
	}
	void Window::OnUpdate()
	{
		glfwPollEvents();
	}
	void Window::SetVSync(bool enabled)
	{
		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);
		m_Data.VSync = enabled;
	}
	bool Window::IsVSync() const
	{
		return m_Data.VSync;
	}
	
	void Window::Init(const WindowProps& props)
	{
		// Setting Data props to equal inputted props
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		E_API_INFO("Creating Window {0}({1}, {2})", props.Title, props.Width, props.Height);


		// Initializing GLFW
		if (!s_GLFWInitialized) {
			int success = glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);
			E_API_ASSERT(success, "Could not load GLFW!");
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_Window);

        int success = gladLoadGL();
        if (!success)
        {
            std::cout << "Failed to load Glad\n";
            exit(-1);
        }


		glfwSetWindowUserPointer(m_Window, &m_Data);

		// Setting GLFW Callbacks-------------------------------------------------------------------

		// Close Callback
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		// Resize Callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;


			WindowResizeEvent event(width, height);
			

			data.EventCallback(event);
		});
		
		// Focus Callback
		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			if(focused)
			{
				WindowFocusEvent event;
				data.EventCallback(event);
			}
			else {
				WindowLostFocusEvent event;
				data.EventCallback(event);
			}
		});


		// Key Callback
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			// TODO : Convert to CEKeys to generalize for crossplatform
			switch (action)
			{
				case GLFW_PRESS: 
				{
					KeyPressedEvent event((KeyCode)key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event((KeyCode)key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event((KeyCode)key, true);
					data.EventCallback(event);
					break;
				}
			}
		});

		// Key Typed Callback
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int codepoint) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event((KeyCode)codepoint);
			data.EventCallback(event);
		});

		// Mouse Callback
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) 
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			// TODO : Convert to CEKeys to generalize for crossplatform
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event((MouseCode)button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event((MouseCode)button);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					MouseButtonPressedEvent event((MouseCode)button);
					data.EventCallback(event);
					break;
				}
			}
		});

		// Mouse Scroll Callback
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xoffset, (float)yoffset);
			data.EventCallback(event);
		});

		// Mouse Position Callback
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((const float)(unsigned int)xpos, (const float)(unsigned int)ypos);
			data.EventCallback(event);
		});
	}
	void Window::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
}
