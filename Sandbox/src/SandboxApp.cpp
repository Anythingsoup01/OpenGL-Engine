#include "Engine/Engine.h"

namespace Engine
{
    class Sandbox : public Application
    {
    public:
        Sandbox()
        {

        }
    };
}

Engine::Application* Engine::CreateApplication()
{
    return new Sandbox();
}
