#include "Shader.h"

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <iostream>

std::string ReadFile1(const char* filePath)
{
    std::ifstream in(filePath, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    std::cout << "Failed to locate " << filePath << "!\n";
    return "";
}

namespace Engine
{
    Shader::~Shader()
    {
        glDeleteShader(m_RendererID);
    }

    void Shader::Init(const char* vertFilePath, const char* fragFilePath)
    {
        std::string vertCode = ReadFile1(vertFilePath);
        std::string fragCode = ReadFile1(fragFilePath);

        const char* vertShaderSource = vertCode.c_str();
        const char* fragShaderSource = fragCode.c_str();

        uint32_t vertShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertShader, 1, &vertShaderSource, NULL);
        glCompileShader(vertShader);
        
        uint32_t fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragShader, 1, &fragShaderSource, NULL);
        glCompileShader(fragShader);

        m_RendererID = glCreateProgram();
        glAttachShader(m_RendererID, vertShader);
        glAttachShader(m_RendererID, fragShader);
        glLinkProgram(m_RendererID);

        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
    }

    void Shader::Bind()
    {
        glUseProgram(m_RendererID);
    }

    void Shader::Unbind()
    {
        glUseProgram(0);
    }

    uint32_t Shader::GetUniformFromMap(const char* uniformName)
    {
        if(m_UniformCache.find(uniformName) != m_UniformCache.end())
            return m_UniformCache.at(uniformName);

        uint32_t id = glGetUniformLocation(m_RendererID, uniformName);
        m_UniformCache.emplace(std::pair<const char*, uint32_t>(uniformName, id));
        return id;
    }

     void Shader::UniformVec1(const char* uniformName, float r)
    {
        glUniform1f(GetUniformFromMap(uniformName), r);
    }
    void Shader::UniformVec3(const char* uniformName, float r, float g, float b)
    {
        glUniform3f(GetUniformFromMap(uniformName), r, g, b);
    }
}
