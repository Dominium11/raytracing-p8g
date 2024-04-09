#pragma once
#include "p8g.hpp"
#include "Vector2D.h"
#include "boundary.h"

class Ray{
    public:
        Ray(Vector2D pos, double angle);
        void draw();
        void lookAt(double x, double y);
        void setPosition(Vector2D pos);
        void setAngle(double angle);
        Vector2D cast(Boundary wall);
    private:
        Vector2D position;
        Vector2D direction;
};