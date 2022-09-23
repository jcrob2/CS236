#ifndef PROJ1_IDAUTOMATON_H
#define PROJ1_IDAUTOMATON_H
#include "Automaton.h"

class IdAutomaton : public Automaton{
public:
    IdAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
};


#endif //PROJ1_IDAUTOMATON_H
