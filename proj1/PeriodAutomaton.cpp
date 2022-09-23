//
// Created by jared on 9/22/2022.
//

#include "PeriodAutomaton.h"

void PeriodAutomaton::S0(const std::string &input) {
    if (input[index] == '.') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}