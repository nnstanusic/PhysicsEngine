#include "followline.h"

FollowLine::FollowLine(std::string name, glm::vec3 orientation)
{

    startingOrientation = orientation;

    std::ifstream stream("../PhysicsEngine/Data/B-SplajnCurves/" + name);

    if(!stream.is_open())
    {
        std::cerr << "Couldn't open" + name << std::endl;
        exit(-1);
    }

    while(stream.good())
    {
        glm::vec3 coordinate;
        stream >> coordinate.x >> coordinate.y >> coordinate.z;
        points.push_back(coordinate);
    }
    points.pop_back();
    pivot = points.begin();


}

void FollowLine::Update()
{
    t += 0.015;

    if(t >= 1){
        t = 0;
        if(pivot < points.end()-4)
        {
            pivot++;
        }else
        {
            pivot = points.begin();
        }
    }

    align(t, pivot);

}

glm::vec3 FollowLine::align(float t,
                            std::vector<glm::vec3>::iterator begin)
{
    glm::vec3 T3(t*t, t, 1 );
    glm::mat3x4 Bi3(-1, 3,-3, 1,
                     2,-4, 2, 0,
                    -1, 0, 1, 0);

    T3*= 0.5f;

    glm::vec4 tmp = T3 * glm::transpose(Bi3);

    glm::vec3 newOrientation(0,0,0);


    for(std::vector<glm::vec3>::iterator i = begin; i < begin + 4; ++i)
    {
        newOrientation += *i * tmp[i - begin];
    }

    glm::vec3 currentOrientation = startingOrientation -
            transform_->GetPosition() +
            newPosition(t, pivot);





    float angle = glm::dot(currentOrientation, newOrientation) /
                 (glm::length(currentOrientation) *
                  glm::length(newOrientation)) ;

    angle =  acos(angle);

    transform_->Rotate(glm::cross(currentOrientation, newOrientation),
                       angle* 180 / 3.14 );

    return currentOrientation;
}


glm::vec3 FollowLine::newPosition(float t,
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

    transform_->SetPosiotion( rez );
    return rez;
}
