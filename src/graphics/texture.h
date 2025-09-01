#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture {
public:
    unsigned int ID{};
    std::string name;
    explicit Texture(const std::string &filename);
    void use() const;
    void destroy() const;

private:
};

#endif