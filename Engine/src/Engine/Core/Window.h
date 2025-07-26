#pragma once

#include <string>
#include <cstdint>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Event/Event.h"

namespace Engine
{
    struct WindowProps
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(std::string title, uint32_t width, uint32_t height)
            : Title(title), Width(width), Height(height) {}
    };
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        Window() = default;
        ~Window();

        void Init(const WindowProps& props);
        void OnUpdate();

        uint32_t GetWidth() const { return m_Data.Width; }
        uint32_t GetHeight() const { return m_Data.Height; }

        void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled);
        bool IsVSync() const;

        GLFWwindow* GetWindow() const { return m_Window; }

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            uint32_t Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    private:
        void Shutdown();
    };
}
