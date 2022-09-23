#include "CommentAutomaton.h"

//Sequence for single line comments = S0, S1, S4*, S5
//Sequence for block comments = S0, S1, S2*, S3, S5

void CommentAutomaton::S0(const std::string& input){
    if (input[index] == '#') {
        inputRead += 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input){
    if (input[index] == '|'){
        inputRead += 1;
        index++;
        S2(input);
    }
    else if (input[index] != '|'){
        inputRead += 1;
        index++;
        S4(input);
    }
    else{
        Serr();
    }
}

void CommentAutomaton::S2(const std::string& input){
    if(input[index] =='|'){
        inputRead += 1;
        index++;
        S3(input);
    }
    else if(input[index] == EOF){
        Serr();
    }
    else if (input[index] != '|') {
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead += 1;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S3(const std::string& input){
    if (input[index] == '#'){
        inputRead += 1;
        index++;
        S5(input);
    }
    else if (input[index] == EOF){
        Serr();
    }
    else if (input[index] != '#'){
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead += 1;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S4(const std::string& input){
    //TODO: remove \n
    if(input[index] == '\n' || input[index] == '\r' || input[index] == EOF){
        //inputRead += 1;
        //index++;
        S5(input);
    }
    else if (input[index] != '\n' && input[index] != EOF){
        inputRead += 1;
        index++;
        S4(input);
    }
    else{
        Serr();
    }
}

void CommentAutomaton::S5(const std::string& input){
    //intentionally empty
}
