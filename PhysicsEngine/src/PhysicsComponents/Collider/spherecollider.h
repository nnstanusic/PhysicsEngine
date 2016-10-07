#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H
#include "collider.h"

class SphereCollider : public Collider
{
public:


    // Collider interface
    void Update();

    //SphereColider
    SphereCollider();
    float radius = 1;


};

#endif // SPHERECOLLIDER_H
