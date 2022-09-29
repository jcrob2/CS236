#include "SchemesAutomaton.h"
void SchemesAutomaton::S0(const std::string &input) {
    if (input[index] == 'S') {
        inputRead += 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S1(const std::string &input){
    if (input[index] == 'c'){
        inputRead += 1;
        index++;
        S2(input);
    }
    else{
        Serr();
    }
}

void SchemesAutomaton::S2(const std::string &input){
    if (input[index] == 'h'){
        inputRead += 1;
        index++;
        S3(input);
    }
    else{
        Serr();
    }
}

void SchemesAutomaton::S3(const std::string &input){
    if (input[index] == 'e'){
        inputRead += 1;
        index++;
        S4(input);
    }
    else{
        Serr();
    }
}

void SchemesAutomaton::S4(const std::string &input){
    if (input[index] == 'm'){
        inputRead += 1;
        index++;
        S5(input);
    }
    else{
        Serr();
    }
}

void SchemesAutomaton::S5(const std::string &input){
    if (input[index] == 'e'){
        inputRead += 1;
        index++;
        S6(input);
    }
    else{
        Serr();
    }
}

void SchemesAutomaton::S6(const std::string &input){
    if (input[index] == 's'){
        inputRead += 1;
        index++;
        S7(input);
    }
    else{
        Serr();
    }
}

void SchemesAutomaton::S7(const std::string &input){
    //intentionally empty
}