#ifndef GRAPHICSFACTORY_H
#define GRAPHICSFACTORY_H
#include "graphicspoligon.h"
#include "graphicscomponent.h"
#include "sphere.h"
#include "cubegraphics.h"
#include "trianglegraphics.h"
#include "particleeffect.h"
#include "memory"

class GraphicsFactory
{

public:
    enum graphicComponent_t{sphere, cube, rectangle, triangle, object};
    static std::unique_ptr<GraphicsComponent>getComponent
            (graphicComponent_t type);


private:
    GraphicsFactory();
};

#endif // GRAPHICSFACTORY_H
