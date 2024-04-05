#pragma once
#include "p8g.hpp"

class Vector2D{
    public:
        Vector2D(){};
        Vector2D(double paramx, double paramy);
        void normalize();
        double x, y;
        double length;
    private:

};
