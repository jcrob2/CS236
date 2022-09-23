#ifndef PROJ1_SCHEMESAUTOMATON_H
#define PROJ1_SCHEMESAUTOMATON_H
#include "Automaton.h"

class SchemesAutomaton : public Automaton{
private:


public:
    SchemesAutomaton() : Automaton(TokenType::SCHEMES) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);
    void S7(const std::string& input);
};


#endif //PROJ1_SCHEMESAUTOMATON_H
