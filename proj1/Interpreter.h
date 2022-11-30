#ifndef PROJ1_INTERPRETER_H
#define PROJ1_INTERPRETER_H
#include "Database.h"
#include "DatalogProgram.h"


class Interpreter {
public:
    Interpreter(DatalogProgram program) {
        this->program = program;
        this->passes = 0;
    }

    Relation* evaluatePredicate(Predicate* p);

    void incPasses(){this->passes += 1;}
    Relation* evalRules();



    void RunInterpreter();
    void InterpretSchemes();
    void InterpretFacts();
    void InterpretRules(); //lab4
    void InterpretQueries();

private:
    DatalogProgram program;
    Database database;
    int passes;
};


#endif //PROJ1_INTERPRETER_H
