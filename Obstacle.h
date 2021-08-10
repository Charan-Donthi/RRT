#ifndef OBSTACLE_H
#define OBSTACLE_H


#include<string>



class Obstacle{

public:
    int left,top,right,bottom,centX,centY,radius;
    int s1,s2,e1,e2;
    int n_points;
    int* points;
    int fillcolor;

public:
    std::string shape;


public:
    void createRectangle(int left,int top,int right,int bottom);
    void createPolygon(int n_points,int* points);
    void createCircle(int centX,int centY,int radius);
    void CreateLine(int s1,int s2,int e1,int e2);
    void setcolor(int color);
    std::string getShape();

};


#endif // OBSTACLE_H
