#ifndef PROJ1_COMMENTAUTOMATON_H
#define PROJ1_COMMENTAUTOMATON_H
#include "Automaton.h"


class CommentAutomaton : public Automaton{
public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);

};


#endif //PROJ1_COMMENTAUTOMATON_H
