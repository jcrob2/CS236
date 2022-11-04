#ifndef PROJ1_INTERPRETER_H
#define PROJ1_INTERPRETER_H
#include "Database.h"
#include "DatalogProgram.h"


class Interpreter {
public:
    Interpreter(DatalogProgram program) {
        this->program = program;
    }
    void RunInterpreter();
    void InterpretSchemes();
    void InterpretFacts();
    //voidInterpretRules(); //lab4
    void InterpretQueries();

private:
    DatalogProgram program;
    Database database;
};


#endif //PROJ1_INTERPRETER_H
