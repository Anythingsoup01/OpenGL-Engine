#pragma once 

#include "Buffers.h"

#include <cstdint>
#include <cstddef>

#include <glad/glad.h>

namespace Engine
{
    class VertexArray
    {
    public:
        VertexArray() = default;
        ~VertexArray();

        void Init();

        void LinkAttrib(VertexBuffer& vbo, uint32_t layout, uint32_t numComponents, GLenum type, size_t stride, void* offset);

        void Bind();
        void Unbind();

        const uint32_t GetRendererID() const { return m_RendererID; }
    private:
        uint32_t m_RendererID;
    };
}
