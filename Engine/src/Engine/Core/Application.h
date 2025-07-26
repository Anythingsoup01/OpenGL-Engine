#pragma once

#include "Renderer/Shader.h"
#include "Renderer/Buffers.h"
#include "Renderer/VertexArray.h"

#include "Window.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"

namespace Engine
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();
        void OnEvent(Event& e);

        inline static Application& Get() { return *s_Instance; }
    private:
        Window m_Window;
        Shader m_Shader;

        VertexArray m_VertexArray;
        VertexBuffer m_VertexBuffer;
        IndexBuffer m_IndexBuffer;

        float m_PosX = 0.0f;
        float m_PosY = 0.0f;

        bool OnWindowClose(WindowCloseEvent& e);
        bool OnKeyPressed(KeyPressedEvent& e);
    private:
        static Application* s_Instance;
        bool m_Running = false;
    };

    Application* CreateApplication();
}
