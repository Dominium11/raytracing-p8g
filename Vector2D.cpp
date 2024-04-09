#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(double paramx, double paramy) : x(paramx), y(paramy) {
    this->length = sqrt((this->x*this->x) + (this->y*this->y)); 
}

void Vector2D::normalize(){
    this->length = sqrt((this->x*this->x) + (this->y*this->y)); 
    this->x = this->x/this->length;
    this->y = this->y/this->length;
}

Vector2D Vector2D::operator+(Vector2D& other){
    Vector2D result(this->x+other.x, this->y+other.y);
    return result;
}