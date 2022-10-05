#include "StringAutomaton.h"
void StringAutomaton::S0(const std::string& input){
    if (input[index] == '\'') {
        inputRead += 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input){
    if (input[index] != '\''){
        if(input[index] == '\n') newLines++;
        inputRead += 1;
        index++;
        S2(input);
    }
    else if (input[index] == '\'') {
        inputRead += 1;
        index++;
        S3(input);
    }
    else{
        Serr();
    }
}

void StringAutomaton::S2(const std::string& input){
    if (input[index] == '\''){
        inputRead += 1;
        index++;
        S4(input);
    }
    else if (input[index] != '\'' && input[index] != EOF) {
        if(input[index] == '\n') newLines++;
        inputRead += 1;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S3(const std::string& input){
    if (input[index] == '\''){
        inputRead += 1;
        index++;
        S1(input);
    }
    else if (input[index] != '\'') {
        //if(input[index] == '\n') newLines++;
        S5(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S4(const std::string& input){
    if (input[index] == '\''){
        inputRead += 1;
        index++;
        S2(input);
    }
    else {
        //if(input[index] == '\n') newLines++;
        S5(input);
    }
}

void StringAutomaton::S5(const std::string& input) {
    //Intentionally blank
}
