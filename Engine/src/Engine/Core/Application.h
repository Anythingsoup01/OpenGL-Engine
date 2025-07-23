#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Renderer/Shader.h"
#include "Renderer/Buffers.h"
#include "Renderer/VertexArray.h"

namespace Engine
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();
    private:
        bool m_Running = false;

        Shader m_Shader;

        VertexArray m_VertexArray;
        VertexBuffer m_VertexBuffer;
        IndexBuffer m_IndexBuffer;

        GLFWwindow* m_Window;
        uint32_t m_Width = 800;
        uint32_t m_Height = 800;
    };

    Application* CreateApplication();
}
