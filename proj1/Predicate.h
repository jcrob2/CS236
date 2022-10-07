#ifndef PROJ1_PREDICATE_H
#define PROJ1_PREDICATE_H
#include "Parameter.h"
#include <vector>
#include <sstream>


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
    Predicate(Predicate* cp){
        this->id = cp->id;
        this->parameters = cp->parameters;
    }

    std::string getId(){return id;}
    std::vector<Parameter*> getParameters(){return parameters;}
    void addParameter(Parameter* p){parameters.push_back(p);}

    std::string toString() const {
        std::ostringstream output;
        std::string padding = "";
        output << this->id << "(";

        for (auto p : parameters){
            output << padding << *p;
            padding = ',';
        }
        output << ")";

        return output.str();
    }

    friend std::ostream& operator<< (std::ostream& os, const Predicate& pred){
        os << pred.toString();
        return os;
    }
};


#endif //PROJ1_PREDICATE_H
