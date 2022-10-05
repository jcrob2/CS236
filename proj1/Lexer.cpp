#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "UndefinedAutomaton.h"
#include "EndOfFileAutomaton.h"
#include "CommentAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QmarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include <sstream>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
//    for (Automaton* obj : automata){
//        delete obj;
//    }
//    automata.clear();
//    for (Token* tok : tokens){
//        delete tok;
//    }
//    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QmarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new EndOfFileAutomaton());
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;

    while (input[0] != EOF) {
        if (input == "") break;
        int maxRead = 0;
        int inputRead = 0;
        maxAutomaton = automata[0];

        //handle whitespace
        //TODO handle tabs and check if file is empty before this stuff
        if (input.size() != 0) {
            while (input[0] == '\n' || input[0] == '\t' || input[0] == '\r' || input[0] == ' ') {
                if (input[0] == '\n') lineNumber++; //This is maybe handled in the Automaton classes
                input.erase(0, 1);
            }
        }

        //Parallel portion
        for (long unsigned int i=0; i < automata.size(); i++){
            inputRead = automata[i]->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i];
                inputRead = 0;
            }
        }

        //Max portion
        if (maxRead > 0) {
            if (input[0] == EOF) break;
            //create substring for token creation from input string to pass into createToken()
            std::string tokString = input.substr(0,maxRead);
            Token* newToken = maxAutomaton->CreateToken(tokString, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();

            //Screen out comments as we don't care about them at all for lab 2
            if (newToken->getType() != TokenType::COMMENT) {
                tokens.push_back(newToken);
            }
        }

        else{
            if (input[0] == EOF) break;
            maxRead = 1;
            //create new automaton for undefined and eof to set maxAutomaton to and then call createToken on max automaton
            std::string tokString = input.substr(0,maxRead);
            maxAutomaton = automata[automata.size()-2];
            Token* newToken = maxAutomaton->CreateToken(tokString, lineNumber);
            tokens.push_back(newToken);
        }
        input.erase(0,maxRead);
    }
    //create new EOF token to add to token vector
    maxAutomaton = automata[automata.size()-1];
    Token* eofToken = maxAutomaton->CreateToken("", lineNumber);
    tokens.push_back(eofToken);
}

std::string Lexer::toString() const {
    std::ostringstream output;
    for(long unsigned int i = 0; i < tokens.size(); i++){
        output << tokens[i]->toString();
    }
    output << "Total Tokens = " << tokens.size();
    return output.str();
}