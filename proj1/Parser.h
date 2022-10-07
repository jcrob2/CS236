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
        this->parseTokens = lexOut;
    }
    ~Parser(){}

    bool match(TokenType tokType);

    //NonTerminal parsing functions
    DatalogProgram* Parse();
    DatalogProgram* parseDatalogProgram(std::vector<Token*> tokens);

    void parseSchemeList(std::vector<Token*> tokens, DatalogProgram* datalogProgram);
    void parseFactList(std::vector<Token*> tokens, DatalogProgram* datalogProgram);
    void parseRuleList(std::vector<Token*> tokens, DatalogProgram* datalogProgram);
    void parseQueryList(std::vector<Token*> tokens, DatalogProgram* datalogProgram);

    void parseScheme(std::vector<Token*> tokens, DatalogProgram* datalogProgram);
    void parseFact(std::vector<Token*> tokens, DatalogProgram* datalogProgram);
    void parseRule(std::vector<Token*> tokens, DatalogProgram* datalogProgram);
    void parseQuery(std::vector<Token*> tokens, DatalogProgram* datalogProgram);

    Predicate* parseHeadPredicate(std::vector<Token*> tokens);
    Predicate* parsePredicate(std::vector<Token*> tokens);

    void parsePredicateList(std::vector<Token*> tokens, Rule* r);
    void parseParameterList(std::vector<Token*> tokens, Predicate* p);
    void parseStringList(std::vector<Token*> tokens, Predicate* p);
    void parseIdList(std::vector<Token*> tokens, Predicate* p);
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
    Parameter* parseId(std::vector<Token*> tokens);
    void parseLeftParen(std::vector<Token*> tokens);
    void parseRightParen(std::vector<Token*> tokens);
    Parameter* parseString(std::vector<Token*> tokens);
    void parsePeriod(std::vector<Token*> tokens);
    void parseColonDash(std::vector<Token*> tokens);
    void parseQMark(std::vector<Token*> tokens);
    void parseComma(std::vector<Token*> tokens);

};


#endif //PROJ1_PARSER_H
