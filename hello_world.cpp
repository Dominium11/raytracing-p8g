#include "p8g.hpp"
#include "boundary.h"
#include "ray.h"
#include "particle.h"
#include "vector"
#include <iostream>

using namespace p8g;

int windowWidth=1000;
int windowHeight=1000;

std::vector<Boundary> walls;

void setup(){
    randomSeed(time(NULL));
    for(int i = 0; i < 5; i++){
        double x1 = random(windowWidth);
        double y1 = random(windowHeight);
        double x2 = random(windowWidth);
        double y2 = random(windowHeight);
        walls.push_back(Boundary(x1, y1, x2, y2));
    }
}

Particle particle(Vector2D(windowWidth/4,windowHeight/2));

void p8g::draw() {
    background(1);
    for(Boundary wall : walls){
        wall.draw();
    }
    particle.update(mouseX, mouseY);
    particle.draw();
    particle.look(walls);
}

void p8g::keyPressed() {}
void p8g::keyReleased() {}

void p8g::mouseMoved() {}

void p8g::mousePressed() {

}

void p8g::mouseReleased() {}
void p8g::mouseWheel(float delta) {}

int main() {
    setup();
    run(windowWidth, windowHeight, "Mouse events");
}