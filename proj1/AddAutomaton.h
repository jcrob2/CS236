#ifndef PROJ1_ADDAUTOMATON_H
#define PROJ1_ADDAUTOMATON_H
#include "Automaton.h"

class AddAutomaton : public Automaton{
public:
    AddAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJ1_ADDAUTOMATON_H
