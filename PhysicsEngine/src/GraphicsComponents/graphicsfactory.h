#ifndef GRAPHICSFACTORY_H
#define GRAPHICSFACTORY_H
#include "graphicscomponent.h"
#include "sphere.h"
#include "cubegraphics.h"
#include "trianglegraphics.h"
#include "memory"

class GraphicsFactory
{

public:
    enum graphicComponent_t{sphere, cube, rectangle, triangle};
    static std::unique_ptr<GraphicsComponent>getComponent
            (graphicComponent_t type);


private:
    GraphicsFactory();
};

#endif // GRAPHICSFACTORY_H
