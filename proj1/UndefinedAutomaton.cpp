#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if (input[index] != '\'' && input[index] != '#'){
        inputRead = 1;
    }
    else if (input[index] == '\''){
        inputRead += 1;
        index++;
        S1(input);
    }
    else if (input[index] == '#'){
        inputRead += 1;
        index++;
        S2(input);
    }
}

void UndefinedAutomaton::S1(const std::string& input){
    if (input[index] == EOF){
        S3(input);
    }
    else {
        inputRead += 1;
        index++;
        S1(input);
    }
}

void UndefinedAutomaton::S2(const std::string& input) {
    if (input[index] == EOF){
        S3(input);
    }
    else {
        inputRead += 1;
        index ++;
        S2(input);
    }
}

void UndefinedAutomaton::S3(const std::string& input){
    //Intentionally empty
}
