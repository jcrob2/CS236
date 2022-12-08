#ifndef PROJ1_INTERPRETER_H
#define PROJ1_INTERPRETER_H
#include "Database.h"
#include "DatalogProgram.h"
#include "Graph.h"
#include <set>
#include <vector>


class Interpreter {
public:
    Interpreter(DatalogProgram program) {
        this->program = program;
        this->passes = 0;
    }

    Relation* evaluatePredicate(Predicate* p);

    void incPasses(){this->passes += 1;}

    void RunInterpreter();
    void InterpretSchemes();
    void InterpretFacts();

    void InterpretRules(); //lab4
    void RunFixedPoint(std::set<Node*> scc);

    void createAdjLists(Graph* F, Graph* R);
    std::vector<std::set<Node*>> RDFSF(Graph* G, std::vector<Node*> &postOrder);
    std::vector<Node*> DFSF(Graph* G);
    std::set<Node*> DFS(Node* N1, std::vector<Node*> &postOrder);

    void InterpretQueries();

private:
    DatalogProgram program;
    Database database;
    int passes;
    std::vector<Relation*> newTups;
};


#endif //PROJ1_INTERPRETER_H
