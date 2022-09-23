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
    if (input[index] != '\'' && (input[index] != '\r' && input[index] != '\n')){
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
    else if (input[index] != '\'') S5(input);
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
        S5(input);
    }
}

void StringAutomaton::S5(const std::string& input) {
    //Intentionally blank
}

/*
void StringAutomaton::S1(const std::string& input){
    if (input[index] == EOF) Serr();
    else if (input[index] != '\'') {
        inputRead += 1;
        index++;
        S2(input);
    }
    else if (input[index] == '\''){
        inputRead += 1;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S2(const std::string& input){
    if (input[index] == EOF) Serr();
    while (input[index] != '\'') {
        inputRead += 1;
        index++;
    }
    if (input[index] == '\'') {
        inputRead += 1;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

//TODO: FINISH
void StringAutomaton::S3(const std::string& input){
    //if (input[index] == EOF) Serr();
    if (input[index] == '\'') {
        inputRead += 1;
        index++;
        S1(input);
    }
    else if (input[index] != '\'') S5(input);
    else {
        Serr();
    }
}

void StringAutomaton::S4(const std::string& input){
    //if (input[index] == EOF) Serr();
    if (input[index] == '\'') {
        inputRead += 1;
        index++;
        S2(input);
    }
    else {
        S5(input);
    }
}

void StringAutomaton::S5(const std::string& input){
    //if (input[index] == EOF) Serr();
   if (input[index] == '\''){
       inputRead += 1;
       index++;
       S2(input);
   }
}
*/