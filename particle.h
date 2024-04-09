#pragma once
#include "p8g.hpp"
#include "Vector2D.h"
#include "ray.h"
#include "vector"

struct Color;

class Particle{
    public:
        Particle(Vector2D, int);
        void draw();
        std::vector<std::pair<double, Color>> look(std::vector<Boundary> walls);
        void update();
        void setPosition(double x, double y);
        void rotate(double angle);
        void move(double moveSpeed);
        double heading;
    private:
        double distance(Vector2D point1, Vector2D point2);
        Vector2D position;
        std::vector<Ray> rays;
        short int resolution;
        int fov;

};