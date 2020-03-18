#pragma once
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <glad/glad.h>

#include <buffer_objects.hpp>
#include <glm/glm.hpp>
#include <mesh.hpp>
#include <ui_drawable.hpp>
#include <vector>

namespace nell::comp
{
struct MeshletTriangleMesh final : Mesh<MeshletTriangleMesh>, UiDrawable
{
  explicit MeshletTriangleMesh(aiMesh* ai_mesh);

  std::vector<glm::vec4> vertices;
  std::vector<glm::vec4> normals;
  std::vector<GLuint> indices;

  size_t getVerticesSize() const { return vertices.size() * getVertexSizeT(); }
  size_t getNormalsSize() const { return normals.size() * getNormalSizeT(); }
  size_t getIndicesSize() const { return indices.size() * getIndexSizeT(); }

  static size_t getVertexSizeT() { return 4 * sizeof(GLfloat); }
  static size_t getNormalSizeT() { return 4 * sizeof(GLfloat); }
  static size_t getIndexSizeT() { return sizeof(GLuint); }

  static GLint getVertexSize() { return 4; }
  static GLint getNormalSize() { return 4; }

  static GLenum getVertexType() { return GL_FLOAT; }
  static GLenum getNormalType() { return GL_FLOAT; }

  void drawImGui() override;
  static unsigned getImportFlags()
  {
    return (aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices |
            aiProcess_ImproveCacheLocality | aiProcess_FlipWindingOrder |
            aiProcess_Triangulate);
  }
};

}  // namespace nell::comp
