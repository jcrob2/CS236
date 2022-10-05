#ifndef PROJ1_PARSER_H
#define PROJ1_PARSER_H
#include "Token.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Parameter.h"
#include "Rule.h"
#include <vector>
#include <iostream>

class Parser {
private:
public:
    Parser(){}
    ~Parser(){}

    DatalogProgram Parse(std::vector<Token*> input);
    void parseDatalogProgram();
    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQueryList();
    void parseScheme();
    void parseFact();
    void parseRule();
    void parseQuery();
    void parseHeadPredicate();
    void parsePredicate();
    void parsePredicateList();
    void parseParameterList();
    void parseStringList();
    void parseIdList();
    void parseParameter();

    std::string toString() const;
    friend std::ostream& operator<< (std::ostream& os, const Parser& p){
        os << p.toString();
        return os;
    }

};


#endif //PROJ1_PARSER_H
