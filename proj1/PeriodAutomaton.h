//
// Created by jared on 9/22/2022.
//

#ifndef PROJ1_PERIODAUTOMATON_H
#define PROJ1_PERIODAUTOMATON_H
#include "Automaton.h"

class PeriodAutomaton : public Automaton{
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJ1_PERIODAUTOMATON_H
