#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <memory>

struct Vertex {
    glm::vec3 pos;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
};

class Mesh
{
public:
    // Mesh data
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    // OpenGL IDs
    unsigned int VAO, VBO, EBO;
    unsigned int shaderProgram;

    // Constructor
    Mesh(const std::vector<Vertex>& verts,
         const std::vector<unsigned int>& inds,
         const std::vector<Texture>& texs,
         unsigned int shader)
        : vertices(verts), indices(inds), textures(texs), shaderProgram(shader)
    {
        SetupMesh();
    }

    // Draw function
    void Draw()
    {
        glUseProgram(shaderProgram);

        // Bind textures if any
        for (unsigned int i = 0; i < textures.size(); ++i)
        {
            glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit
            glBindTexture(GL_TEXTURE_2D, textures[i].id);
        }

        // Draw mesh
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // Reset to default texture unit
        glActiveTexture(GL_TEXTURE0);
    }

private:
    void SetupMesh()
    {
        // Generate VAO, VBO, EBO
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        // VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        // EBO
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        // Vertex attributes
        // Position
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
        // Normal
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        // TexCoords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));

        glBindVertexArray(0);
    }
};