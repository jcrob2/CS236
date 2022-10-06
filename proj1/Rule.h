#ifndef PROJ1_RULE_H
#define PROJ1_RULE_H
#include "Predicate.h"


class Rule {
public:
    Predicate* headPredicate;
    std::vector<Predicate*> bodyPredicates;
public:
    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Rule& rule){
        os << rule.toString();
        return os;
    }
};


#endif //PROJ1_RULE_H
