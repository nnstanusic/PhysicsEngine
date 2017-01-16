#ifndef GRAPHICSPOLIGON_H
#define GRAPHICSPOLIGON_H

#include "graphicscomponent.h"

#include <GL/glut.h>
#include <GL/gl.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>


#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class GraphicsPoligon : public virtual GraphicsComponent
{
public:

    void Draw() override;
    // GraphicsPoligon members
    enum enFormat{wavefront};

    GraphicsPoligon(std::string, enFormat);
    ~GraphicsPoligon();

private:
    std::ifstream stream;
    void LoadWaveFront();
    std::vector < glm::vec3 > vertices;
    std::vector < glm::vec2 > uvs;
    std::vector < glm::vec3 > normals;

};

#endif // GRAPHICSPOLIGON_H
