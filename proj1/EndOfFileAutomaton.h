#ifndef PROJ1_ENDOFFILEAUTOMATON_H
#define PROJ1_ENDOFFILEAUTOMATON_H
#include "Automaton.h"

class EndOfFileAutomaton : public Automaton{
public:
    EndOfFileAutomaton() : Automaton(TokenType::ENDOFFILE) {}  // Call the base constructor

    void S0(const std::string& input);

};


#endif //PROJ1_ENDOFFILEAUTOMATON_H
