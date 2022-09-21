#include "EndOfFileAutomaton.h"

void EndOfFileAutomaton::S0(const std::string &input) {
    if (input[index] == '\377') {
        inputRead = 1;
    }
}