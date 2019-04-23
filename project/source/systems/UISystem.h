#pragma once

namespace Components {
class Sprite;
class Transform;
} // namespace Components

class UISystem {
public:
    static void Setup2DCamera();
    static void Render(const cp::Sprite& sprite, cp::Transform& transform);
};