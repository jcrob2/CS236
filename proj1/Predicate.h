#ifndef PROJ1_PREDICATE_H
#define PROJ1_PREDICATE_H
#include "Parameter.h"
#include <vector>


class Predicate {
private:
    std::string id;
    std::vector<Parameter*> parameters;
public:
    Predicate(){}
    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Predicate& pred){
        os << pred.toString();
        return os;
    }
};


#endif //PROJ1_PREDICATE_H
