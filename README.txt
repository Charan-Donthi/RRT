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
4. Change start and end points if you wish in main program at lines 47 and 48. Just change the coordinates
5. Run the program  

Changing range:
Here range value in function "getMinCostParentWithinRange(vector<Node*> nodes,int x2,int y2,int range,vector<Obstacle> obstacles)"
will allow random points to be made within the circular radius of nodes.
Higher the value higher the straight lines and optimum path but less speed 
lower the value lower the straight lines and optimum path but high speed.


Resources and References

RRT and RRT* algorithm references:
https://www.youtube.com/watch?v=QR3U1dgc5RE
https://www.youtube.com/watch?v=4Rd_gTYIft8&t=2341s
https://www.youtube.com/watch?v=qg2uqpyo0Xs
https://www.youtube.com/watch?v=YKiQTJpPFkA

C++ graphics programming references
https://www.youtube.com/watch?v=pywM36qKHvg
https://www.youtube.com/watch?v=8uM8omF7SVc&t=305s
https://www.includehelp.com/c/draw-circle-and-rectangle.aspx#:~:text=To%20draw%20a%20rectangle%20in,int%20right%2C%20int%20bottom)%3B
https://www.geeksforgeeks.org/draw-line-c-graphics/





