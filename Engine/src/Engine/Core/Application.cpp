#include "Application.h"

#include <glad/glad.h>

#include <iostream>

extern bool g_ApplicationRunning;

float vertices[8 * 4] = 
{
    -0.5f, -0.5f, 0.0f,    1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,    1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
     0.5f, 0.5f, 0.0f,     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
    -0.5f, 0.5f, 0.0f,     1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
};

uint32_t indices[3 * 2]
{
    0, 1, 2,
    2, 3, 0
};


namespace Engine
{
    Application::Application()
    {
        m_Window.Init({"Engine", 800, 800});
        m_Window.SetVSync(true);
        m_Window.SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

        // Shader
        m_Shader.Init("resources/shaders/default.vert", "resources/shaders/default.frag");

        // Vertex Array
        m_VertexArray.Init();

        // Vertex & Index Buffer
        m_VertexBuffer.Init(vertices, sizeof(vertices));
        m_IndexBuffer.Init(indices, 6);
        
        // Make a function that takes an array
        /*
         *
         * m_VertexBuffer.SetLayout({
         *      {ShaderType::Vec3, "aPosition"},
         * });
         *
         * m_VertexArray.AddVertexBuffer(m_VertexBuffer);
         * 
        */
        m_VertexArray.LinkAttrib(m_VertexBuffer, 0, 3, GL_FLOAT, sizeof(float) * 8, (void*)0);
        m_VertexArray.LinkAttrib(m_VertexBuffer, 1, 3, GL_FLOAT, sizeof(float) * 8, (void*)(sizeof(float) * 3));
        m_VertexArray.LinkAttrib(m_VertexBuffer, 2, 2, GL_FLOAT, sizeof(float) * 8, (void*)(sizeof(float) * 6));

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);   
    }

    Application::~Application()
    {

        g_ApplicationRunning = false;
    }

    void Application::Run()
    {
        m_Running = true;
        while (m_Running) 
        {
            m_Window.OnUpdate();
            glClear(GL_COLOR_BUFFER_BIT);

            // Bind Shader
            m_Shader.Bind();
            m_Shader.UniformVec3("uPosition", m_PosX, m_PosY, 0.0f);
            m_Shader.UniformVec1("uScale", 0.5f);
            // Bind Textures
            
            // Bind VertexArray
            m_VertexArray.Bind();
            //glBindVertexArray(m_VertexArrayID);
            // Draw Elements
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            
            glfwSwapBuffers(m_Window.GetWindow());
            glfwPollEvents();
        }
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyPressed));
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return false;
    }

    bool Application::OnKeyPressed(KeyPressedEvent& e)
    {
        switch (e.GetKeyCode())
        {
             case KeyCode::W :
                m_PosY += .01f;
                break;
            case KeyCode::S:
                m_PosY -= .01f;
                break;
           case KeyCode::D :
                m_PosX += .01f;
                break;
            case KeyCode::A :
                m_PosX -= .01f;
                break;
        }

        return false;
    }
}
