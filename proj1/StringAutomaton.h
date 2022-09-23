#ifndef PROJ1_STRINGAUTOMATON_H
#define PROJ1_STRINGAUTOMATON_H
#include "Automaton.h"

class StringAutomaton : public Automaton{
public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
};


#endif //PROJ1_STRINGAUTOMATON_H
