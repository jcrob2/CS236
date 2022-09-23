//
// Created by jared on 9/22/2022.
//

#include "QmarkAutomaton.h"

void QmarkAutomaton::S0(const std::string &input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}