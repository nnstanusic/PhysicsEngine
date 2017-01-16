#ifndef FOLLOWLINE_H
#define FOLLOWLINE_H

#include "aicomponent.h"
#include <vector>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

class FollowLine : public virtual AIComponent
{
public:
    FollowLine(std::string, glm::vec3);

    // AIComponent interface
    void Update();

    // f


private:
    glm::vec3 newPosition(float, std::vector<glm::vec3>::iterator);
    glm::vec3 align(float, std::vector<glm::vec3>::iterator);
    std::vector<glm::vec3> points;
    std::vector<glm::vec3>::iterator pivot;
    glm::vec3 startingOrientation;

    float t = 0.0f;
};

#endif // FOLLOWLINE_H
