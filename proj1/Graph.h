//
// Created by jared on 12/6/2022.
//

#ifndef PROJ1_GRAPH_H
#define PROJ1_GRAPH_H
#include "Node.h"
#include <map>
#include <set>
#include <vector>

class Graph {
public:
    Graph(){}
    Graph(int numNodes){
        for(int i = 0; i < numNodes; i++){
            Node* node = new Node();
            node->index = i;
            this->nodes.insert({i, node});
        }

    }

    std::map<int, Node*> GetNodes(){return this->nodes;}
    void markNodesUnvisited(){
        for (auto n : this->GetNodes()){
            n.second->visited = false;
        }
    }

    //std::vector<Node*> GetPostOrder() const {return this->po;}
    //void SetPostOrder(std::vector<Node*> p){this->po = p;}
    void AddEdge(int from, int to){
        nodes.at(from)->adjacentTo.insert(nodes.at(to));
    }
private:
    std::map<int, Node*> nodes;
    //std::vector<Node*> po;
};


#endif //PROJ1_GRAPH_H
