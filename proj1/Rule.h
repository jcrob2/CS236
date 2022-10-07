#ifndef PROJ1_RULE_H
#define PROJ1_RULE_H
#include "Predicate.h"


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



    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Rule& rule){
        os << rule.toString();
        return os;
    }
};


#endif //PROJ1_RULE_H
