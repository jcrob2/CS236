#ifndef PROJ1_QMARKAUTOMATON_H
#define PROJ1_QMARKAUTOMATON_H
#include "Automaton.h"

class QmarkAutomaton : public Automaton{
public:
    QmarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJ1_QMARKAUTOMATON_H
