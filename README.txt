Project: RRT and RRT* (rapidly exploring random trees) path planing algorithm implemented in C++.
Author:Donthi Charan Sai
Date:8/8/2021 and 9/8/2021

Description:The project was build and executed in Code::Blocks IDE
It uses graphics files for grahical simulation.
Program is RRT* modified after implementing RRT

Including extra files for graphics:
The following link has step by step process to setup winBGIm library
https://www.geeksforgeeks.org/include-graphics-h-codeblocks/

Steps to Run Program:
1. Simply download and include graphics file required.
2. Open the main program
3. Add obstacles if you need in "declareObstacles()" function, We have already included some obstacles 
4. Change start and end points if you wish in main program
5. Run the program  

Changing range:
Here range value in function "getMinCostParentWithinRange(vector<Node*> nodes,int x2,int y2,int range,vector<Obstacle> obstacles)"
will allow random points to be made within the circular radius of nodes.
Higher the value higher the straight lines and optimum path but less speed 
lower the value lower the straight lines and optimum path but high speed.
