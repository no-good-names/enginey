#ifndef MODEL_H
#define MODEL_H

class Model {
public:
    Model(const float *vertices, int vertex_count, const unsigned int *indices, int indices_count);
    Model(const float *vertices, int vertex_count, const unsigned int *indices, int indices_count, const unsigned int *texture_uvs);
    void use() const;
private:
    unsigned int VAO{};
    int indices_count;
};

#endif