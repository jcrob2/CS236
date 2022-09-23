#include "FactsAutomaton.h"
void FactsAutomaton::S0(const std::string &input) {
    if (input[index] == 'F') {
        inputRead += 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S1(const std::string &input) {
    if (input[index] == 'a') {
        inputRead += 1;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::S2(const std::string &input) {
    if (input[index] == 'c') {
        inputRead += 1;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void FactsAutomaton::S3(const std::string &input) {
    if (input[index] == 't') {
        inputRead += 1;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S4(const std::string &input) {
    if (input[index] == 's') {
        inputRead += 1;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}

void FactsAutomaton::S5(const std::string &input) {
    //intentionally empty
}