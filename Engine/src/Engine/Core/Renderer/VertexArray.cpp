#include "VertexArray.h"

namespace Engine
{
    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void VertexArray::Init()
    {
        glGenVertexArrays(1, &m_RendererID);
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::LinkAttrib(VertexBuffer& vbo, uint32_t layout, uint32_t numComponents, GLenum type, size_t stride, void* offset)
    {
        vbo.Bind();
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
        vbo.Unbind();
    }

    void VertexArray::Bind()
    {
        glBindVertexArray(m_RendererID);
    }

    void VertexArray::Unbind()
    {
        glBindVertexArray(0);
    }
}
