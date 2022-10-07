#include "Lexer.h"
#include "Parser.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char** argv) {

    std::ifstream in;
    in.open(*(argv+1));
    char ch;
    std::string input;

    while (true) {
        if (in.eof())
            break;
        ch = in.get();
        input += ch;
    }
    in.close();

    //create and run the lexer
    Lexer* lexer = new Lexer();
    //lexer->Run(input);
    //std::cout << *lexer;
    std::vector<Token*> lexOut = lexer->Run(input);
    //std::cout << *lexer;
    Parser* parser = new Parser(lexOut);
    DatalogProgram* dp = new DatalogProgram(parser->Parse());

    std::cout << *dp;

    delete parser;
    delete lexer;

    return 0;
}