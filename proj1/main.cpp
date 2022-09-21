#include "Lexer.h"
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    // check command line arguments
//    if (argc != 2) {
//        std::cout << "usage: " << argv[0] << " input_file" << std::endl;
//        return 1;
//    }
//
//    // open file
//    std::string fileName = argv[1];
//    std::ifstream input(fileName);
//    if (!input.is_open()) {
//        std::cout << "File " << fileName << " could not be found or opened." << std::endl;
//        return 1;
//    }

    std::ifstream in;
    in.open(*(argv+1));
    char ch;
    std::string input;

    while (true) {
        if (in.eof())
            break;
        ch = in.get();
        input += ch;
        //std::cout << ch;
    }
    //std::cout << input;
    in.close();




    Lexer* lexer = new Lexer();
    lexer->Run(input);
    std::cout << *lexer;
    // TODO

    delete lexer;

    return 0;
}