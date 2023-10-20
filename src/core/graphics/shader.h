#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>
#include <unordered_map>

namespace Hunga::Graphics {
    class Shader {
        public:
            Shader(const std::string& vertex, const std::string& fragment);
            ~Shader();

            void Bind();
            void UnBind();

            void SetUniformInt(const std::string& name, int value);
            void SetUniformFloat(const std::string& name, float value);
            void SetUniformFloat2(const std::string& name, float value0, float value1);
            void SetUniformFloat3(const std::string& name, float value, float value1, float value2);
            void SetUniformFloat4(const std::string& name, float value, float value1, float value2, float value3);

        private:
            int GetUniformLocation(std::string);

            uint32_t m_ProgramID;
            std::unordered_map<std::string, int> m_UniformLocation;
    };
}

#endif