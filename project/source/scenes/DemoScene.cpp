#include "DemoScene.h"

#include "../behaviours/Hovercraft.h"
#include "../components/Camera.h"
#include "../components/Light.h"
#include "../components/MeshCollider.h"
#include "../components/Renderable.h"
#include "../components/Rigidbody.h"
#include "../components/Sprite.h"
#include "../components/Transform.h"

#include "../systems/BehaviourSystem.h"

#include "../rendering/Material.h"
#include "../resources/MeshResource.h"
#include "../resources/ResourceLoader.h"
#include "../resources/ShaderResource.h"
#include "../resources/TextureResource.h"

namespace cp = Components;
namespace bh = Behaviours;

void DemoScene::load() {
}