#pragma once
#include "p8g.hpp"
#include "Vector2D.h"

class Boundary{
    public:
        Boundary(int x1, int y1, int x2, int y2);
        void draw();
        Vector2D getPointA();
        Vector2D getPointB();
    private:
        Vector2D a;
        Vector2D b;
};