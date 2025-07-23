#pragma once

#include <cstdint>
#include <cstddef>

namespace Engine
{
    class VertexBuffer
    {
    public:
        VertexBuffer() = default;
        ~VertexBuffer();

        void Init(float* vertices, size_t size);

        void Bind();
        void Unbind();

        const uint32_t GetRendererID() const { return m_RendererID; }
    private:
        uint32_t m_RendererID;
    };

    class IndexBuffer
    {
    public:
        IndexBuffer() = default;
        ~IndexBuffer();

        void Init(uint32_t* indices, int count);

        void Bind();
        void Unbind();

        const uint32_t GetRendererID() const { return m_RendererID; }
    private:
        uint32_t m_RendererID;
    };
}
