#include "graphicsfactory.h"

GraphicsFactory::GraphicsFactory()
{

}



std::unique_ptr<GraphicsComponent> GraphicsFactory::getComponent
    (GraphicsFactory::graphicComponent_t type)
{
    switch (type) {
    case sphere:
        return std::make_unique<Sphere>();
    case cube:
        return std::make_unique<CubeGraphics>();
    case triangle:
        return std::make_unique<TriangleGraphics>();

    default:
        return nullptr;
    }
}
