#include "Lexer.h"
#include <string>
#include <iostream>
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




    Lexer* lexer = new Lexer();
    lexer->Run(input);
    std::cout << *lexer;

    delete lexer;

    return 0;
}