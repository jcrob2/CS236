#ifndef PROJ1_MULTIPLYAUTOMATON_H
#define PROJ1_MULTIPLYAUTOMATON_H
#include "Automaton.h"
class MultiplyAutomaton : public Automaton {
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJ1_MULTIPLYAUTOMATON_H
