#include "Node.h"

Node::Node(int xcod,int ycod,Node *parent,int d){
            this->cost=0;
            this->xcod=xcod;
            this->ycod=ycod;
            this->parent=parent;
            if(parent)
                this->cost=parent->cost+d;
        }
