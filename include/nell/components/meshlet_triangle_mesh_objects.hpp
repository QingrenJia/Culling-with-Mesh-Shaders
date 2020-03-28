#pragma once
#include <glad/glad.h>

#include <nell/components/buffer_objects.hpp>
#include <nell/components/ui_drawable.hpp>

namespace nell::comp
{
struct MeshletTriangleMeshObjects final : BufferObjects, UiDrawable
{
  void drawImGui() override;
  GLuint vertex_descriptor_ssbo;
  GLuint meshlet_descriptor_ssbo;
  GLuint index_ssbo;
};

inline void MeshletTriangleMeshObjects::drawImGui()
{
  ImGui::BulletText("MeshletTriangleMeshObjects");
}

}  // namespace nell::comp
