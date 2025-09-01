#ifndef SHADER_H
#define SHADER_H

#include <iostream>

#include <glm/glm.hpp>

class Shader {
public:
    unsigned int ID;

    Shader(const std::string &vertexPath, const std::string &fragmentPath);
    ~Shader();
    void use() const;
    void destroy();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, glm::vec2) const;
    void setVec3(const std::string &name, glm::vec3) const;
    void setVec4(const std::string &name, glm::vec4) const;
    void setMat2(const std::string &name, glm::mat2) const;
    void setMat3(const std::string &name, glm::mat3) const;
    void setMat4(const std::string &name, glm::mat4) const;

private:
    static void checkCompileErrors(unsigned int shader, const std::string &type);
};

#endif //SHADER_H
