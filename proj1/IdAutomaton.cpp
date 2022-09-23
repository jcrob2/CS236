//
// Created by jared on 9/22/2022.
//

#include "IdAutomaton.h"
#include <cctype>
void IdAutomaton::S0(const std::string &input) {

    if (isalpha(input[index])) {
        inputRead += 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string &input) {
    while (isalnum(input[index])){
        inputRead += 1;
        index++;
    }
    if (!isalnum(input[index])){
        //Serr();
        S2(input);
    }
    else {
       //S2(input);
       Serr();
    }
}

void IdAutomaton::S2(const std::string &input) {
    //Intentionally blank
}

