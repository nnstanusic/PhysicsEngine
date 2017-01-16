#ifndef RIGIDBODY_H
#define RIGIDBODY_H
#include "transform.h"
#include <vector>
#include <cmath>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <iostream>


class Rigidbody
{
public:
    Rigidbody();
    void Update();
    void Init(Transform*);
    void Bounce(glm::vec3);
    void SetMass(float);
private:
    void updateGravity();
    void airResistance();
    void updateVelocity();
    void updateAcceleration();

    int signf(float);

    Transform* transform_;
    std::vector<float[3]> forcePoints;


    float gravity = 9.81f; //m/s^2
    float mass = 1.0f; //kg
    const float deltaTime = 0.016; //s
    float bounciness = -0.7;   // Coefficient of restitution ("bounciness")
    float airDensity = 1.2;  // Density of air. Try 1000 for water.
    float coeficientOfDrag = 0.47; // Coeffecient of drag for a ball

    glm::vec3 force;
    glm::vec3 acceleration;
    glm::vec3 velocity;
    

};

#endif // RIGIDBODY_H
