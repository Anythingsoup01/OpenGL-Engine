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

        uint32_t GetUniformFromMap(const char* uniformName);

        void UniformVec1(const char* uniformName, float r);
        void UniformVec3(const char* uniformName, float r, float g, float b);

    private:
        uint32_t m_RendererID;
        std::unordered_map<const char*, uint32_t> m_UniformCache;
    };
}
