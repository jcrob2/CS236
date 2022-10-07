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
    Predicate(std::string in){ id = in;}
    Predicate(std::string in, std::vector<Parameter*> vin){
        id = in;
        parameters = vin;
    }

    void addParameter(Parameter* p){parameters.push_back(p);}

    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Predicate& pred){
        os << pred.toString();
        return os;
    }
};


#endif //PROJ1_PREDICATE_H
