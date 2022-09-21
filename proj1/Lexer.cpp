#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "UndefinedAutomaton.h"
#include "EndOfFileAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (Automaton* obj : automata){
        delete obj;
    }
    automata.clear();
    for (Token* tok : tokens){
        delete tok;
    }
    tokens.clear();
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());

    // TODO: Add the other needed automata here

    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new EndOfFileAutomaton());
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;

    //TODO: reduce the size of the input after a get a token
    while (input[0] != EOF) {
        int maxRead = 0;
        int inputRead = 0;
        maxAutomaton = automata[0];

        //handle whitespace
        //TODO handle tabs and check if file is empty before this stuff
        if (input[0] == '\n'){
            //lineNumber++; This is maybe handled in the Automaton classes
            input.erase(input.begin());
        }
        else if (input[0] == ' ') {
            input.erase(input.begin());
        }

        //Parallel portion
        for (auto eachAutomaton : automata){
        //for (int i=0; i < automata.size(); i++){
            inputRead = eachAutomaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = eachAutomaton;
            }
        }

        //Max portion
        if (maxRead > 0) {
            //create substring for token creation from input string to pass into createToken()
            std::string tokString = input.substr(0,maxRead);
            //TODO: token doesn't update with tokString and lineNumber correctly and is stuck on the COLON tokenType
            Token* newToken = maxAutomaton->CreateToken(tokString, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }

        else{
            maxRead = 1;
            //create new automaton for undefined and eof to set maxAutomaton to and then call createToken on max automaton
            maxAutomaton = automata[automata.size()-2];
            Token* newToken = maxAutomaton->CreateToken(input, lineNumber);
            tokens.push_back(newToken);
        }
        input.erase(0,maxRead);
    }
    maxAutomaton = automata[automata.size()-1];
    Token* eofToken = maxAutomaton->CreateToken(input, lineNumber);
    tokens.push_back(eofToken);
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata
        // TODO: you need to handle whitespace inbetween tokens
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}