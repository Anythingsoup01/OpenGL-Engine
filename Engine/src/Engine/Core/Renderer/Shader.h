#pragma once

#include <cstdint>

namespace Engine
{
    class Shader
    {
    public:
        Shader() = default;
        ~Shader();

        void Init(const char* vertShaderPath, const char* fragShaderPath);

        void Bind();
        void Unbind();

        const uint32_t GetRendererID() const { return m_RendererID; }

    private:
        uint32_t m_RendererID;
    };
}
