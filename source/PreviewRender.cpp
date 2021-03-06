#include "archlab/PreviewRender.h"
#include "archlab/Evaluator.h"

#include <unirender/DrawState.h>
#include <painting3/RenderSystem.h>
#include <node0/SceneNode.h>
#include <node3/RenderSystem.h>

namespace archlab
{

PreviewRender::PreviewRender(const pt3::Viewport& vp,
                             const sm::mat4& cam_mat)
    : m_vp(vp)
    , m_cam_mat(cam_mat)
{
}

void PreviewRender::DrawNode3D(const ur::Device& dev, ur::Context& ctx,
                               const pt0::RenderContext& rc,
                               const n0::SceneNode& node,
                               bool draw_face, bool draw_shape) const
{
    pt3::RenderParams rp;
    rp.painter  = &m_pt;
    rp.viewport = &m_vp;
    rp.cam_mat  = &m_cam_mat;

    ur::DrawState ds;

    if (!draw_shape) {
        rp.mask.set(pt3::RenderParams::NotDrawShape);
    }

    // draw face
    if (draw_face) {
        rp.mask.reset(pt3::RenderParams::DrawMeshBorder);
        n3::RenderSystem::Draw(dev, ctx, ds, node, rp, rc);
    }

    // draw edge
    rp.mask.set(pt3::RenderParams::DrawMeshBorder);
    n3::RenderSystem::Draw(dev, ctx, ds, node, rp, rc);
}

}