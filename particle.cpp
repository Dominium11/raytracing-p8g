#include "particle.h"
#include "math.h"

using namespace p8g;

struct Color;

Particle::Particle(Vector2D pos, int fov){
    this->fov = fov;
    position = pos;
    heading = 0;
    resolution = 2;
    for(int i = -fov*resolution / 2; i < fov*resolution / 2; i++){
        Ray ray(this->position, i * (3.14159265359 / 180)/resolution);
        this->rays.push_back(ray);
    }
}

void Particle::rotate(double angle){
    this->heading += angle;
    int index = 0;
    for(int a = -this->fov*resolution / 2; a < this->fov*resolution / 2; a++){
        this->rays[index].setAngle((a * (3.14159265359 / 180))/resolution + this->heading);
        index++;
    }
}

void Particle::move(double direction){
    Vector2D velocity = Vector2D(cos(this->heading)*direction,sin(this->heading)*direction);
    this->position = this->position + velocity;
}

void Particle::setPosition(double x, double y){
    Vector2D temp(x,y);
    position = temp;
}

void Particle::update(){
    for(Ray & ray : this->rays){
        ray.setPosition(this->position);
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

std::vector<std::pair<double, Color>> Particle::look(std::vector<Boundary> walls){
    std::vector<std::pair<double, Color>> scene;
    for(Ray ray : this->rays){
        Vector2D closest(0,0);
        Color color = {255,255,255};
        //This realistically should always be bigger than any position;
        double record = 999999999999999999;
        for(Boundary wall : walls){
            Vector2D point = ray.cast(wall);
            if(point.x != 0 && point.y != 0){
                double dist = distance(position, point);
                if(dist < record){
                    record = dist;
                    closest = point;
                    color = wall.color;
                }
            }
        }
        if(closest.x != 0 && closest.y != 0){
            line(position.x, position.y, closest.x, closest.y);
        }
        auto test = std::make_pair(record, color);
        scene.push_back(test);
    }
    return scene;
}