#pragma once
#include "p8g.hpp"
#include "Vector2D.h"
#include "ray.h"
#include "vector"

class Particle{
    public:
        Particle(Vector2D);
        void draw();
        void look(std::vector<Boundary> walls);
        void update(double x, double y);
        void setPosition(double x, double y);
    private:
        double distance(Vector2D point1, Vector2D point2);
        Vector2D position;
        std::vector<Ray> rays;
};