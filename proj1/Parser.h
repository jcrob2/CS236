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
    int index;
    std::vector<Token*> parseTokens;
public:
    Parser() {}
    Parser(std::vector<Token*> lexOut){
        index = 0;
        parseTokens = lexOut;
    }
    ~Parser(){}

    bool match(TokenType tokType);

    //NonTerminal parsing functions
    DatalogProgram Parse();
    void parseDatalogProgram(std::vector<Token*> tokens);
    void parseSchemeList(std::vector<Token*> tokens);
    void parseFactList(std::vector<Token*> tokens);
    void parseRuleList(std::vector<Token*> tokens);
    void parseQueryList(std::vector<Token*> tokens);
    void parseScheme(std::vector<Token*> tokens);
    void parseFact(std::vector<Token*> tokens);
    void parseRule(std::vector<Token*> tokens);
    void parseQuery(std::vector<Token*> tokens);
    void parseHeadPredicate(std::vector<Token*> tokens);
    void parsePredicate(std::vector<Token*> tokens);
    void parsePredicateList(std::vector<Token*> tokens);
    void parseParameterList(std::vector<Token*> tokens);
    void parseStringList(std::vector<Token*> tokens);
    void parseIdList(std::vector<Token*> tokens);
    Parameter* parseParameter(std::vector<Token*> tokens);

    //Terminal parsing functions
    // SCHEMES COLON FACTS RULES QUERIES ENDOFFILE ID
    // LEFT_PAREN RIGHT_PAREN STRING PERIOD
    // COLON_DASH Q_MARK COMMA
    void parseSchemes(std::vector<Token*> tokens);
    void parseColon(std::vector<Token*> tokens);
    void parseFacts(std::vector<Token*> tokens);
    void parseRules(std::vector<Token*> tokens);
    void parseQueries(std::vector<Token*> tokens);
    void parseEndOfFile(std::vector<Token*> tokens);
    std::string parseId(std::vector<Token*> tokens);
    void parseLeftParen(std::vector<Token*> tokens);
    void parseRightParen(std::vector<Token*> tokens);
    void parseString(std::vector<Token*> tokens);
    void parsePeriod(std::vector<Token*> tokens);
    void parseColonDash(std::vector<Token*> tokens);
    void parseQMark(std::vector<Token*> tokens);
    void parseComma(std::vector<Token*> tokens);


    std::string toString() const;
    friend std::ostream& operator<< (std::ostream& os, const Parser& p){
        os << p.toString();
        return os;
    }

};


#endif //PROJ1_PARSER_H
