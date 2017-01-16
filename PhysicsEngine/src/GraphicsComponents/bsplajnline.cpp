#include "bsplajnline.h"

BsplajnLine::BsplajnLine(std::string name)
{

    std::ifstream stream("../PhysicsEngine/Data/B-SplajnCurves/" + name);

    if(!stream.is_open())
    {
        std::cerr << "Couldn't open" + name << std::endl;
        exit(-1);
    }

    std::vector<glm::vec3> tmpPoints;
    while(stream.good())
    {
        glm::vec3 coordinate;
        stream >> coordinate.x >> coordinate.y >> coordinate.z;
        tmpPoints.push_back(coordinate);
    }

    tmpPoints.pop_back();
    pivot = tmpPoints.begin();
    glm::vec3 point;
    for(auto i = tmpPoints.begin(); i != tmpPoints.end()-3; ++i)
    {
        while(1)
        {
            point = newPosition(t, pivot);

            points.push_back(point);
            t += 0.001;

            if(t >= 1){
                t = 0;
                if(pivot < points.end()-4)
                {
                    pivot++;
                }
                break;
            }

        }
    }



}


void BsplajnLine::Draw()
{
    glBegin(GL_LINE_STRIP);


    for(auto i = points.begin(); i != points.end()-4; ++i)
    {
       glVertex3f( i->x, i->y, i->z);
    }

    glEnd();
}

glm::vec3 BsplajnLine::newPosition(float t,
                                   std::vector<glm::vec3>::iterator begin)
{
    glm::vec4 T3(t*t*t, t*t, t, 1);
    glm::mat4 Bi3(-1, 3,-3, 1,
                   3,-6, 3, 0,
                  -3, 0, 3, 0,
                   1, 4, 1, 0);


    T3 /= 6.0f;

    glm::vec4 tmp = T3 * glm::transpose(Bi3);

    glm::vec3 rez(0,0,0);

    for(std::vector<glm::vec3>::iterator i = begin; i < begin + 4; ++i)
    {

        rez += *i * tmp[i - begin];
    }
    return rez;
}
