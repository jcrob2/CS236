#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    Automaton* maxAutomaton;

    std::string toString() const;

    friend std::ostream& operator<< (std::ostream& os, const Lexer& lex){
        os << lex.toString();
        return os;
    }
    // TODO: add other public methods here

};

#endif // LEXER_H

