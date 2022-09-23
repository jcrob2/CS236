#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if (input[index] != '\'' && input[index] != '#'){
        //if(input[index] == '\n') newLines++;
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
        S5(input);
    }
    else if (input[index] == '\''){
        inputRead += 1;
        index++;
        S3(input);
    }
    else {
        if(input[index] == '\n') newLines++;
        inputRead += 1;
        index++;
        S1(input);
    }
}

void UndefinedAutomaton::S2(const std::string& input) {
    if (input[index] == '|'){
        inputRead += 1;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S3(const std::string& input){
    if (input[index] == '\''){
        inputRead += 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void UndefinedAutomaton::S4(const std::string& input){
    if (input[index] == EOF){
        S5(input);
    }
    else if (input[index] == '|'){
        inputRead += 1;
        index++;
        S6(input);
    }
    else {
        if(input[index] == '\n') newLines++;
        inputRead += 1;
        index++;
        S4(input);
    }
}

void UndefinedAutomaton::S5(const std::string& input){
    //Intentionally empty
}

void UndefinedAutomaton::S6(const std::string& input){
    if (input[index] == EOF){
        S5(input);
    }
    else if (input[index] == '#'){
        Serr();
    }
    else {
        if(input[index] == '\n') newLines++;
        inputRead += 1;
        index++;
        S4(input);
    }
}
