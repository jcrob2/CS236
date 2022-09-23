#ifndef PROJ1_FACTSAUTOMATON_H
#define PROJ1_FACTSAUTOMATON_H
#include "Automaton.h"

class FactsAutomaton : public Automaton{
private:


public:
    FactsAutomaton() : Automaton(TokenType::FACTS) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
};


#endif //PROJ1_FACTSAUTOMATON_H
