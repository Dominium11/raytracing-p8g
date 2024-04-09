#include "ray.h"
#include "math.h"
using namespace p8g;

Ray::Ray(Vector2D pos, double angle){
    position = pos;
    direction = Vector2D(cos(angle),sin(angle));
}

void Ray::setAngle(double angle){
    direction = Vector2D(cos(angle),sin(angle));
}

void Ray::draw(){
    stroke(255);
    push();
    translate(position.x, position.y);
    line(0, 0, direction.x * 10, direction.y * 10);
    pop();
}

void Ray::setPosition(Vector2D pos){
    this->position = pos;
}

void Ray::lookAt(double x, double y){
    this->direction.x = x - this->position.x;
    this->direction.y = y - this->position.y;
    this->direction.normalize();
}

Vector2D Ray::cast(Boundary wall){
    //https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
    //Position of wall points
    double x1 = wall.getPointA().x;
    double y1 = wall.getPointA().y;
    double x2 = wall.getPointB().x;
    double y2 = wall.getPointB().y;

    //Position of line from xy3 to xy4
    double x3 = this->position.x;
    double y3 = this->position.y;
    double x4 = this->position.x + this->direction.x;
    double y4 = this->position.y + this->direction.y;

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if(denominator==0){
        //Basically a return false;

        return Vector2D(0,0);
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

    if(t > 0 && t < 1 && u > 0){
        double x = x1 + t * (x2 - x1);
        double y = y1 + t * (y2 - y1);
        Vector2D point(x,y);

        return point;
    }else{
        //Basically a return false;
        return Vector2D(0,0);
    }
}