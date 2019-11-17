#pragma once

#include <tessellation/Painter.h>
#include <painting0/RenderContext.h>

namespace n0 { class SceneNode; }
namespace pt3 { class Viewport; }

namespace cgav
{

class RenderSystem
{
public:
    RenderSystem(const pt3::Viewport& vp, const sm::mat4& cam_mat);

    void DrawNode3D(const pt0::RenderContext& rc, const n0::SceneNode& node) const;
//    void DrawNode2D(const cga::Node& back, const bp::Node& front) const;

    auto& GetPainter() const { return m_pt; }

private:
    const pt3::Viewport& m_vp;
    const sm::mat4&      m_cam_mat;

    mutable tess::Painter m_pt;

}; // RenderSystem

}