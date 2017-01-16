#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include "transform.h"

class AIComponent
{
public:
    AIComponent();
    virtual void Update(void) =0;
    void Init(Transform*);
protected:
    Transform* transform_;
};

#endif // AICOMPONENT_H
