#include "Renderer.h"

#include <glad/glad.h>
#include <iostream>

namespace Engine
{
    Renderer::Renderer()
    {
        int success = gladLoadGL();
        if (!success)
        {
            std::cout << "Failed to load glad!\n";
            exit(-1);
        }
    }

    Renderer::~Renderer()
    {

    }
}
