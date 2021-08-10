#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<list>
#include<stdlib.h>
#include<string>
#include<time.h>
#include "Node.h"
#include <vector>
#include <cmath>
#include "Obstacle.h"
#include "Point.h"
#include<math.h>
#include<iostream>

using namespace std;

bool checkForObstacleInBetween(Node node,int xcod,int ycod,vector<Obstacle> obstacles);
int abs (int n);
vector<Point> getLinePoints(Node node,int xcod,int ycod);
Node* getNearestNode(vector<Node*> nodes,int xcod,int ycod);
double getDistance(int x1,int y1,int x2,int y2);
void initializeObstacles(vector<Obstacle> obstacles);
vector<Obstacle> declareObstacles();
bool ranPointWithinRange(vector<Node*> nodes,int x2,int y2);
Node* getMinCostParentWithinRange(vector<Node*> nodes,int x2,int y2,int range,vector<Obstacle> obstacles);
void initializeNodes(Node* start,Node* dest);






int main()
{

initwindow(1000,1000);
setbkcolor(WHITE);
cleardevice();

vector<Obstacle> obstacles=declareObstacles();
initializeObstacles(obstacles);
vector<Node*> nodes;

int ranX,ranY;

Node start(10,10,&start,0);
Node dest(800,300,NULL,0);

initializeNodes(&start,&dest);
nodes.push_back(&start);

cout<<start.xcod<<endl;
cout<<start.ycod<<endl;

Node *t;

setcolor(GREEN);
srand(time(0));

while(true){
    ranX=rand()%1000;
    ranY=rand()%1000;
    if(!ranPointWithinRange(nodes,ranX,ranY))
            continue;
    t=getMinCostParentWithinRange(nodes,ranX,ranY,100,obstacles);
    if(t){
    Node *p=new Node(ranX,ranY,t,getDistance(ranX,ranY,t->xcod,t->ycod));
    nodes.push_back(p);
    line(t->xcod,t->ycod,ranX,ranY);
    if(getDistance(ranX,ranY,dest.xcod,dest.ycod)<=15) break;
    //delay(0);
    }
}

setcolor(RED);
setlinestyle(0,0,3);
t=nodes.back();

while(true){
    if(t->xcod==start.xcod && t->ycod==start.ycod) break;
    line(t->xcod,t->ycod,t->parent->xcod,t->parent->ycod);
    t=t->parent;
    delay(100);
}

getch();
closegraph();

return 0;

}








void initializeNodes(Node* start,Node* dest){
    setcolor(MAGENTA);
    circle(start->xcod,start->ycod,10);
    setfillstyle(SOLID_FILL,MAGENTA);
    floodfill(start->xcod,start->ycod,MAGENTA);

    circle(dest->xcod,dest->ycod,10);
    floodfill(dest->xcod,dest->ycod,MAGENTA);
}




bool ranPointWithinRange(vector<Node*> nodes,int x,int y){
    for(int i=0;i<nodes.size();i++){
        if(getDistance(nodes[i]->xcod,nodes[i]->ycod,x,y)<=50)
            return true;
    }

    return false;

}





Node* getMinCostParentWithinRange(vector<Node*> nodes,int x2,int y2,int range,vector<Obstacle> obstacles){

    int dis;
    int mincost;
    Node *temp=NULL;
    bool flag=true;


    for(int i=0;i<nodes.size();i++){
            dis=getDistance(nodes[i]->xcod,nodes[i]->ycod,x2,y2);
            if(dis<=range && !checkForObstacleInBetween(*nodes[i],x2,y2,obstacles)){
                    if(flag){
                        temp=nodes[i];
                        mincost=temp->cost+getDistance(temp->xcod,temp->ycod,x2,y2);
                        flag=false;
                    }
                    if(nodes[i]->cost+dis<mincost){
                        mincost=nodes[i]->cost+dis;
                        temp=nodes[i];
                    }
            }

    }

    return temp;
}




vector<Obstacle> declareObstacles(){
    vector<Obstacle> obstacles;

Obstacle ob1;
ob1.createRectangle(10,40,150,60);
ob1.setcolor(BLACK);

Obstacle ob2;
ob2.createRectangle(500,400,550,450);
ob2.setcolor(BLACK);

Obstacle ob3;
ob3.createRectangle(150,150,200,200);
ob3.setcolor(BLACK);

Obstacle ob4;
ob4.createRectangle(500,200,700,350);
ob4.setcolor(BLACK);

Obstacle ob5;
ob5.createRectangle(400,500,600,600);
ob5.setcolor(BLACK);

Obstacle ob6;
ob6.createRectangle(350,200,400,350);
ob6.setcolor(BLACK);

Obstacle ob7;
ob7.createRectangle(700,20,750,250);
ob7.setcolor(BLACK);

Obstacle ob8;
ob8.createRectangle(600,450,700,550);
ob8.setcolor(BLACK);

Obstacle ob9;
ob9.createRectangle(250,100,300,600);
ob9.setcolor(BLACK);

Obstacle ob10;
ob10.createRectangle(900,100,1000,600);
ob10.setcolor(BLACK);

Obstacle ob11;
ob11.createRectangle(800,700,890,800);
ob11.setcolor(BLACK);

Obstacle ob12;
ob12.createRectangle(10,650,500,780);
ob12.setcolor(BLACK);

obstacles.push_back(ob1);
obstacles.push_back(ob2);
obstacles.push_back(ob3);
obstacles.push_back(ob4);
obstacles.push_back(ob5);
obstacles.push_back(ob6);
obstacles.push_back(ob7);
obstacles.push_back(ob8);
obstacles.push_back(ob9);
obstacles.push_back(ob10);
obstacles.push_back(ob11);
obstacles.push_back(ob12);

return obstacles;

}




bool checkForObstacleInBetween(Node node,int xcod,int ycod,vector<Obstacle> obstacles){
    vector<Point> linePoints;
    linePoints=getLinePoints(node,xcod,ycod);
    for(int i=0;i<obstacles.size();i++){
        for(int j=0;j<linePoints.size();j++)
            if(linePoints[j].xcod>=obstacles[i].left && linePoints[j].xcod<=obstacles[i].right && linePoints[j].ycod>=obstacles[i].top && linePoints[j].ycod<=obstacles[i].bottom)
                return true;
    }

    return false;
}




vector<Point> getLinePoints(Node node,int xcod,int ycod){

    vector<Point> points;

    int dx = node.xcod - xcod;
    int dy = node.ycod - ycod;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = xcod;
    float Y = ycod;
    for (int i = 0; i <= steps; i++)
    {
        points.push_back(Point(round(X),round(Y)));
        X += Xinc;
        Y += Yinc;
    }

    return points;


}





Node* getNearestNode(vector<Node*> nodes,int xcod,int ycod){

    double dis;
    double mindis=getDistance(nodes[0]->xcod,nodes[0]->ycod,xcod,ycod);
    Node *nearestNode=nodes[0];
    for(int i=1;i<nodes.size();i++){
        dis=getDistance(nodes[i]->xcod,nodes[i]->ycod,xcod,ycod);
        if(dis<mindis){
            mindis=dis;
            nearestNode=nodes[i];
        }
    }

    return nearestNode;

}




double getDistance(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}





void initializeObstacles(vector<Obstacle> obstacles){
   for(int i=0;i<obstacles.size();i++){
        setcolor(obstacles[i].fillcolor);
        setfillstyle(SOLID_FILL,obstacles[i].fillcolor);
        if(obstacles[i].shape=="Rectangle"){
            rectangle(obstacles[i].left,obstacles[i].top,obstacles[i].right,obstacles[i].bottom);
            floodfill(obstacles[i].left+2,obstacles[i].top+2,obstacles[i].fillcolor);
        }else if(obstacles[i].shape=="Circle"){
            circle(obstacles[i].centX,obstacles[i].centY,obstacles[i].radius);
        }else if(obstacles[i].shape=="Line"){
            line(obstacles[i].s1,obstacles[i].s2,obstacles[i].e1,obstacles[i].e2);
        }else if(obstacles[i].shape=="Polygon"){
            drawpoly(obstacles[i].n_points,obstacles[i].points);
        }else{
        }
   }

}





int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}



