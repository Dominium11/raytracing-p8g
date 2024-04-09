#include "boundary.h"
using namespace p8g;

Boundary::Boundary(int x1, int y1, int x2, int y2, Color color){
    a.x = x1;
    a.y = y1;
    b.x = x2;
    b.y = y2;
    this->color = color;
}

void Boundary::draw(){
    stroke(color.r, color.g, color.b, 255);
    line(a.x, a.y, b.x, b.y);
}

Vector2D Boundary::getPointA(){
    return this->a;
}

Vector2D Boundary::getPointB(){
    return this->b;
}