#include <log.h>

#include <glad/glad.h>
#include <core/graphics/shader.h>

namespace  Hunga::Graphics {
    Shader::Shader(const std::string& vertex, const std::string& fragment) {
        m_ProgramID = glCreateProgram();

        int status = GL_FALSE;
        char ErrorLog[512];

        uint32_t vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        {

            const GLchar* glSource = vertex.c_str();
            glShaderSource(vertexShaderID, 1, &glSource, NULL);

            glCompileShader(vertexShaderID);
            glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &status);

            if (status != GL_TRUE) {
                glGetShaderInfoLog(vertexShaderID, sizeof(ErrorLog), NULL, ErrorLog);
                NUT_ERROR("Vertex Shader Compilation Error: {}", ErrorLog);
                glDeleteShader(vertexShaderID);
            } else {
                glAttachShader(m_ProgramID, vertexShaderID);
            }
        }


        uint32_t fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        if (status == GL_TRUE) {

            const GLchar* glSource = fragment.c_str();
            glShaderSource(fragmentShaderID, 1, &glSource, NULL);

            glCompileShader(fragmentShaderID);
            glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &status);

            if (status != GL_TRUE) {
                glGetShaderInfoLog(fragmentShaderID, sizeof(ErrorLog), NULL, ErrorLog);
                NUT_ERROR("Fragment Shader Compilation Error: {}", ErrorLog);
                glDeleteShader(fragmentShaderID);
            } else {
                glAttachShader(m_ProgramID, fragmentShaderID);
            }
        }

        NUT_ASSERT(status == GL_TRUE, "Failed to compile Shader... ");

        if (status = GL_TRUE)  {
            glLinkProgram(m_ProgramID);
            glValidateProgram(m_ProgramID);
            glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &status);

            if (status != GL_TRUE) {
                glGetProgramInfoLog(m_ProgramID, sizeof(ErrorLog), NULL, ErrorLog);
                NUT_ERROR("Failed linking Shader to program: {}", ErrorLog);
                glDeleteProgram(m_ProgramID);
                m_ProgramID = -1;
            }
        }

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);
    }

    void Shader::Bind() {
        glUseProgram(m_ProgramID);
    }    
    
    void Shader::UnBind() {
        glUseProgram(0);
    }

    void Shader::SetUniformInt(const std::string& name, int value) {
        glUseProgram(m_ProgramID);
        glUniform1i(GetUniformLocation(name), value);
    }

    void Shader::SetUniformFloat(const std::string& name, float value) {
        glUseProgram(m_ProgramID);
        glUniform1f(GetUniformLocation(name), value);
    }

    void Shader::SetUniformFloat2(const std::string& name, float value0, float value1) {
        glUseProgram(m_ProgramID);
        glUniform2f(GetUniformLocation(name), value0, value1);
    }

    void Shader::SetUniformFloat3(const std::string& name, float value0, float value1, float value2) {
        glUseProgram(m_ProgramID);
        glUniform3f(GetUniformLocation(name), value0, value1, value2);
    }

    void Shader::SetUniformFloat4(const std::string& name, float value0, float value1, float value2, float value3) {
        glUseProgram(m_ProgramID);
        glUniform4f(GetUniformLocation(name), value0, value1, value2, value3);
    }

    int Shader::GetUniformLocation(std::string name) {
        auto it = m_UniformLocation.find(name);

        if (it == m_UniformLocation.end()) {
            m_UniformLocation[name] = glGetUniformLocation(m_ProgramID, name.c_str());
        }

        return m_UniformLocation[name];
    }

    Shader::~Shader() {
        glUseProgram(0);
        glDeleteProgram(m_ProgramID);
    }
}