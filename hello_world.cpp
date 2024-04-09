#include "p8g.hpp"
#include "boundary.h"
#include "ray.h"
#include "particle.h"
#include "vector"
#include <iostream>
#include <random>
#include <Windows.h>

using namespace p8g;

int fov = 45;

int windowWidth=1600;
int windowHeight=800;

int topDownWidth = windowWidth/2;
int topDownHeight = windowHeight;

int sceneWidth = windowWidth/2;
int sceneHeight = windowHeight;

std::vector<std::pair<double, Color>> scene;
std::vector<Boundary> walls;


double randnum (double a, double b)
{
  static std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution (a,b);
  return distribution(generator);
}

void setup(){
    for(int i = 0; i < 6; i++){
        double x1 = randnum(0, topDownWidth);
        double y1 = randnum(0, topDownHeight);
        double x2 = randnum(0, topDownWidth);
        double y2 = randnum(0, topDownHeight);
        walls.push_back(Boundary(x1, y1, x2, y2, Color(randnum(0,255),randnum(0,255),randnum(0,255))));
    }
    walls.push_back(Boundary(1, 1, topDownWidth, 1));
    walls.push_back(Boundary(topDownWidth, 1, topDownWidth, topDownHeight));
    walls.push_back(Boundary(topDownWidth, topDownHeight, 1, topDownHeight));
    walls.push_back(Boundary(1, topDownHeight, 1, 1));
}

Particle particle(Vector2D(windowWidth/4,windowHeight/2), fov);

void p8g::draw() {
    //Handling keyboard
    if(GetKeyState('A') & 0x8000){
        particle.rotate(-0.02);
    }
    if(GetKeyState('D') & 0x8000){
        particle.rotate(0.02);
    }
    if(GetKeyState('W') & 0x8000){
        particle.move(1);
    }
    if(GetKeyState('S') & 0x8000){
        particle.move(-1);
    }

    background(1);
    for(Boundary wall : walls){
        wall.draw();
    }
    particle.update();
    particle.draw();
    scene = particle.look(walls);

    double w = sceneWidth / scene.size();
    push();
    translate(sceneWidth, 0);
    for(int i = 0; i < scene.size(); i++){
        noStroke();
        std::vector<double> sceneColors;
        std::vector<double> sceneHeights;
        for(int j = 0; j < scene.size(); j++){
            double squared = (scene[j].first/255)*(scene[j].first/255);
            //double heightSquared = sceneHeight*sceneHeight;
            sceneColors.push_back(255/squared);  //Calculate brighntess from inverse square law
            sceneHeights.push_back(20 * sceneHeight/(2*tan((fov/2) * (3.14159265359 / 180))*scene[i].first)); //Calculate wallheight depending on perspective (costly cuz of tangens)
        }
        //Draw a found wall
        fill(scene[i].second.r, scene[i].second.g, scene[i].second.b, sceneColors[i]);
        rectMode(CENTER);
        rect(i*w + w/2, sceneHeight/2, w, sceneHeights[i]);
        //Draw the sky above
        fill(135, 206, 235);
        rect(i*w + w/2, 0, w, sceneHeight - sceneHeights[i]);
        //Draw the sky above
        fill(19, 109, 21);
        rect(i*w + w/2, sceneHeight, w, sceneHeight - sceneHeights[i]);
    }
    pop();

}

void p8g::keyPressed() {}
void p8g::keyReleased() {
    if(keyCode){
        keyCode = 0;
    }
}

void p8g::mouseMoved() {}

void p8g::mousePressed() {

}

void p8g::mouseReleased() {}
void p8g::mouseWheel(float delta) {}

int main() {
    setup();
    run(windowWidth, windowHeight, "Mouse events");
}