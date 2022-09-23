//
// Created by jared on 9/22/2022.
//

#include "RulesAutomaton.h"
void RulesAutomaton::S0(const std::string &input) {
    if (input[index] == 'R') {
        inputRead += 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S1(const std::string &input) {
    if (input[index] == 'u') {
        inputRead += 1;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S2(const std::string &input) {
    if (input[index] == 'l') {
        inputRead += 1;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S3(const std::string &input) {
    if (input[index] == 'e') {
        inputRead += 1;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S4(const std::string &input) {
    if (input[index] == 's') {
        inputRead += 1;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S5(const std::string &input) {
    //intentionally empty
}