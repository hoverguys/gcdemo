#pragma once

#include "Transform.h"

namespace Components {

/*! \brief Light component
 *  Gives the entity control over one of the 8 lights in the scene
 *  NOTE: This is an abstract class and cannot be instantiated
 */
class Light {
protected:
    explicit Light(const GXColor color) : color(color){};

public:
    /*! Light color */
    GXColor color;

    /*! \brief Set up light matrices and other settings
     *  \param view      View matrix
     *  \param transform Entity's transform
     */
    virtual void Setup(const Matrix& view, const Transform& transform, GXLightObj& lightObject) const = 0;
};

/*! \brief Point light component
 *  Gives the entity a point light
 */
class PointLight : public Light {
public:
    explicit PointLight(const GXColor color) : Light(color){};
    void Setup(const Matrix& view, const Transform& transform, GXLightObj& lightObject) const override;
};

/*! \brief Point light component
 *  Gives the entity a directional light
 */
class DirectionalLight : public Light {
public:
    float shininess;
    explicit DirectionalLight(const GXColor color, const float shininess = 0) : Light(color), shininess(shininess){};
    void Setup(const Matrix& view, const Transform& transform, GXLightObj& lightObject) const override;
};

} // namespace Components