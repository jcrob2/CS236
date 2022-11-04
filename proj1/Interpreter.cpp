#include "Interpreter.h"

void Interpreter::RunInterpreter() {
    InterpretSchemes();
    InterpretFacts();
//    InterpretRules();
    InterpretQueries();
}

void Interpreter::InterpretSchemes() {
    for (Predicate scheme:program.getSchemes()){
        std::vector<std::string> vec;
        for (Parameter* par:scheme.getParameters()){
            vec.push_back(par->getParameter());
        }
        Header* header = new Header(vec);
        Relation* relation = new Relation(scheme.getId(), *header);
        relation->SetHeader(*header);
        database.AddRelation(*relation);
    }
}

void Interpreter::InterpretFacts() {
    for (Predicate fact:program.getFacts()){
        std::vector<std::string> vec;
        std::string key = fact.getId();
        for(Parameter* par:fact.getParameters()){
            vec.push_back(par->getParameter());
        }
        Tuple* tuple = new Tuple(vec);
        Relation* r = database.GetRelation(key);
        r->AddTuple(*tuple);
    }
}

//void Interpreter::InterpretRules() {}

void Interpreter::InterpretQueries() {
    for(Predicate query:program.getQueries()){

    }
}