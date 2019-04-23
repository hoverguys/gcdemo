#include "pchheader.h"
#include "Light.h"

namespace Components {

void PointLight::Setup(const Matrix& view, const Transform& transform, GXLightObj& lightObject) const {
    Vector pos = view.Multiply(transform.position);

    GX_InitLightColor(&lightObject, color);
    GX_InitLightPosv(&lightObject, &pos);
}

void DirectionalLight::Setup(const Matrix& view, const Transform& transform, GXLightObj& lightObject) const {
    Vector dir = view.MultiplySR(transform.forward);

    GX_InitLightSpot(&lightObject, 180.0, GX_SP_OFF);
    GX_InitSpecularDirv(&lightObject, &dir);
    GX_InitLightDistAttn(&lightObject, 1, 1, GX_DA_OFF);
    GX_InitLightAttn(&lightObject, 1, 0, 0, 1, 0.1, 0);
    GX_InitLightColor(&lightObject, color);
    GX_InitLightShininess(&lightObject, shininess);
}

} // namespace Components