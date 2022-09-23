#ifndef PROJ1_LEFTPARENAUTOMATON_H
#define PROJ1_LEFTPARENAUTOMATON_H
#include "Automaton.h"

class LeftParenAutomaton : public Automaton {
public:
    LeftParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJ1_LEFTPARENAUTOMATON_H
