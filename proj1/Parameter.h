#ifndef PROJ1_PARAMETER_H
#define PROJ1_PARAMETER_H
#include <string>

class Parameter {
    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Parameter& par){
        os << par.toString();
        return os;
    }
};


#endif //PROJ1_PARAMETER_H
