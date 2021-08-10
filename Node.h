#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int xcod;
        int ycod;
        int cost;
        Node *parent;
        Node(int xcod,int ycod,Node *parent,int d);
};

#endif // NODE_H
