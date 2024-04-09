#pragma once
#include "p8g.hpp"

class Vector2D{
    public:
        Vector2D(){};
        Vector2D(double paramx, double paramy);
        void normalize();
        Vector2D operator+(Vector2D& other);
        double x, y;
        double length;
    private:

};
