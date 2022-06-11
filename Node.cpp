#include <iostream>
#include <string>



class Node{
    public:
        Node();
        ~Node();
        char *res;
        Node* nxt;
    
};

Node::Node(){
    
    nxt = NULL;
}

Node::~Node(){
    delete[] res;
    nxt = NULL;
}

