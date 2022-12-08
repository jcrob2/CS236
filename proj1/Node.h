//
// Created by jared on 12/6/2022.
//

#ifndef PROJ1_NODE_H
#define PROJ1_NODE_H
#include <set>

struct Node{
    int index;
    Node(){this->visited = false;}
    std::set<Node*> adjacentTo;
    bool visited;

    bool operator<(Node* other) const{
        if (this->index < other->index){
            return true;
        }
        else {
            return false;
        }
    }
};

#endif //PROJ1_NODE_H
