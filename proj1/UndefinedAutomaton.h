//
// Created by jared on 9/20/2022.
//

#ifndef PROJ1_UNDEFINEDAUTOMATON_H
#define PROJ1_UNDEFINEDAUTOMATON_H
#include "Automaton.h"

class UndefinedAutomaton : public Automaton
{
public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);

};


#endif //PROJ1_UNDEFINEDAUTOMATON_H
