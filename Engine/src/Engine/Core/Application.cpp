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
        int success = glfwInit();
        if (!success)
        {
            std::cout << "Failed to load GLFW\n";
            exit(-1);
        }
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(m_Width, m_Height, "OpenGL-Engine", NULL, NULL);
        glfwMakeContextCurrent(m_Window);

        success = gladLoadGL();
        if (!success)
        {
            std::cout << "Failed to load Glad\n";
            exit(-1);
        }
        glViewport(0, 0, m_Width, m_Height);

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
        glfwDestroyWindow(m_Window);
        glfwTerminate();

        g_ApplicationRunning = false;
    }

    void Application::Run()
    {
        m_Running = true;
        while (m_Running && !glfwWindowShouldClose(m_Window)) 
        {
            glClear(GL_COLOR_BUFFER_BIT);

            // Bind Shader
            m_Shader.Bind();
            // Bind Textures
            
            // Bind VertexArray
            m_VertexArray.Bind();
            //glBindVertexArray(m_VertexArrayID);
            // Draw Elements
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }
    }
}
