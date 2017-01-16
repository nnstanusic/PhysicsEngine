#ifndef BSPLAJNLINE_H
#define BSPLAJNLINE_H

#include "graphicscomponent.h"
#include <GL/gl.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class BsplajnLine : public virtual GraphicsComponent
{
public:
    BsplajnLine(std::string);

    // GraphicsComponent interface

    void Draw() override;

    // BsplajnLine methods
private:
    glm::vec3 newPosition(float, std::vector<glm::vec3>::iterator);

    std::vector<glm::vec3> points;

    std::vector<glm::vec3>::iterator pivot;

    float t{0};
};

#endif // BSPLAJNLINE_H
