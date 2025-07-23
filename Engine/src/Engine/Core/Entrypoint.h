#pragma once

extern Engine::Application* Engine::CreateApplication();
bool g_ApplicationRunning = true;

namespace Engine
{
    int Main(int argc, char** argv)
    {
        // Initialize Logger
        while (g_ApplicationRunning)
        {
            Application* app = CreateApplication();
            app->Run();
            delete app;
        }
        return 0;
    }
}

int main(int argc, char** argv)
{
    Engine::Main(argc, argv);
}
