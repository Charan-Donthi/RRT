#include "Obstacle.h"


void Obstacle::createRectangle(int left,int top,int right,int bottom){
        this->left=left;
        this->top=top;
        this->right=right;
        this->bottom=bottom;
        shape="Rectangle";
    }

void Obstacle::createPolygon(int n_points,int* points){
        this->n_points=n_points;
        this->points=points;
        shape="Polygon";
    }

void Obstacle::createCircle(int centX,int centY,int radius){
        this->centX=centX;
        this->centY=centY;
        this->radius=radius;
        shape="Circle";
    }

void Obstacle::CreateLine(int s1,int s2,int e1,int e2){
        this->s1=s1;
        this->s2=s2;
        this->e1=e1;
        this->e2=e2;
        shape="Line";
    }

void Obstacle::setcolor(int color){
        this->fillcolor=color;
    }

std::string Obstacle::getShape(){
        return this->shape;
    }


