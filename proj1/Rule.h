#ifndef PROJ1_RULE_H
#define PROJ1_RULE_H
#include "Predicate.h"
#include <vector>
#include <iostream>
#include <sstream>


class Rule {
public:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;
public:
    Rule(){}
    Rule(Predicate* ch){
        this->headPredicate = ch;
    }
    Rule(Predicate* ch, std::vector<Predicate*> cv){
        this->headPredicate = ch;
        this->bodyPredicates = cv;
    }
    Rule(Rule* cr){
        this->headPredicate = cr->headPredicate;
        this->bodyPredicates = cr->bodyPredicates;
    }

    ~Rule(){}

    void addPredicate(Predicate* pin){
        this->bodyPredicates.push_back(pin);
    }

    std::vector<std::string> getHeaderVals(){
        std::vector<std::string> v;
        for (auto const &a : this->headPredicate->getParameters()){
            v.push_back(a->getParameter());
        }
        return v;
    }

    std::vector<Predicate*> getBodyPredicates(){return bodyPredicates;}

    std::string toString() const {
        std::ostringstream output;
        std::string padding = "";
        output << *headPredicate << " :- ";
        for (auto p : bodyPredicates){
            output << padding << *p;
            padding = ",";
        }

        return output.str();
    }

    friend std::ostream& operator<< (std::ostream& os, const Rule& rule){
        os << rule.toString();
        return os;
    }
};


#endif //PROJ1_RULE_H
