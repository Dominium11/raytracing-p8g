#include "particle.h"
#include "math.h"

using namespace p8g;

Particle::Particle(Vector2D pos){
    position = pos;
    for(int i = 0; i < 360; i++){
        Ray ray(this->position, i * (3.14159265359 / 180));
        this->rays.push_back(ray);
    }
}

void Particle::setPosition(double x, double y){
    Vector2D temp(x,y);
    position = temp;
}

void Particle::update(double x, double y){
    setPosition(x,y);
    Vector2D pos(x,y);
    for(Ray & ray : this->rays){
        ray.setPosition(pos);
    }
}

void Particle::draw(){
    for(Ray ray : this->rays){
        ray.draw();
    }
}

double Particle::distance(Vector2D p1, Vector2D p2){
    return sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
}

void Particle::look(std::vector<Boundary> walls){
    for(Ray ray : this->rays){
        Vector2D closest(0,0);
        //This realistically should always be bigger than any position;
        double record = 999999999999999999;
        for(Boundary wall : walls){
            Vector2D point = ray.cast(wall);
            if(point.x != 0 && point.y != 0){
                double dist = distance(position, point);
                if(dist < record){
                    record = dist;
                    closest = point;
                }
            }
        }
        if(closest.x != 0 && closest.y != 0){
            line(position.x, position.y, closest.x, closest.y);
        }
    }
}