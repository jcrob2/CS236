//
// Created by jared on 9/22/2022.
//

#ifndef PROJ1_RIGHTPARENAUTOMATON_H
#define PROJ1_RIGHTPARENAUTOMATON_H
#include "Automaton.h"

class RightParenAutomaton : public Automaton{
public:
    RightParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJ1_RIGHTPARENAUTOMATON_H
