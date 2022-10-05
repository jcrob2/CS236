#ifndef PROJ1_RULE_H
#define PROJ1_RULE_H


class Rule {
    std::string toString() const {}

    friend std::ostream& operator<< (std::ostream& os, const Rule& rule){
        os << rule.toString();
        return os;
    }
};


#endif //PROJ1_RULE_H
