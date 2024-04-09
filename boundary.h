#pragma once
#include "p8g.hpp"
#include "Vector2D.h"
#include "color.h"

class Boundary{
    public:
        Color color;
        Boundary(int x1, int y1, int x2, int y2, Color color = {255,255,255});
        void draw();
        Vector2D getPointA();
        Vector2D getPointB();
    private:
        Vector2D a;
        Vector2D b;
};