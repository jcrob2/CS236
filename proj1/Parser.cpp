#include "Parser.h"

bool Parser::match(TokenType tokType) {
    if (parseTokens[index]->getType() == tokType){
        return true;
    }
    else {
        return false;
    }
}

DatalogProgram Parser::Parse() {
    try {
        DatalogProgram* datalogProgram = new DatalogProgram();
        parseDatalogProgram(parseTokens, datalogProgram);
        std::cout << "Success!" << std::endl;
    } catch (Token* error) {
        std::cout << "Failure!" << std::endl;
        std::cout << "  " << *error;
    }

}

//Non-Terminal parsing functions
void Parser::parseDatalogProgram(std::vector<Token*> tokens, DatalogProgram* datalogProgram) {
    //SCHEMES == First set of DatalogProgram
    if (match(TokenType::SCHEMES)) {
        parseSchemes(tokens);
        parseColon(tokens);
        parseScheme(tokens, datalogProgram);
        parseSchemeList(tokens, datalogProgram);
        parseFacts(tokens);
        parseColon(tokens);
        parseFactList(tokens, datalogProgram);
        parseRules(tokens);
        parseColon(tokens);
        parseRuleList(tokens);
        parseQueries(tokens);
        parseColon(tokens);
        parseQuery(tokens);
        parseQueryList(tokens);
        parseEndOfFile(tokens);
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseSchemeList(std::vector<Token*> tokens, DatalogProgram* datalogProgram) {
    //ID == first set of SchemeList
    if(match(TokenType::ID)){
        parseScheme(tokens, datalogProgram);
        parseSchemeList(tokens, datalogProgram);
    }
    //FACTS == Follow set of SchemeList
    else if (match(TokenType::FACTS)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseFactList(std::vector<Token *> tokens, DatalogProgram* datalogProgram) {
    //ID == FIRST set of FactList
    if(match(TokenType::ID)){
        parseFact(tokens, datalogProgram);
        parseFactList(tokens, datalogProgram);
    }
    //RULES == FOLLOW set of FactList
    else if (match(TokenType::RULES)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseRuleList(std::vector<Token *> tokens) {
    //ID == FIRST set of RuleList
    if(match(TokenType::ID)){
        parseRule(tokens);
        parseRuleList(tokens);
    }
    //QUERIES == FOLLOW set of RuleList
    else if (match(TokenType::QUERIES)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseQueryList(std::vector<Token *> tokens) {
    //ID == FIRST set of QueryList
    if(match(TokenType::ID)){
        parseQuery(tokens);
        parseQueryList(tokens);
    }
    //ENDOFFILE == FOLLOW set of QueryList
    else if (match(TokenType::ENDOFFILE)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}

void Parser::parseScheme(std::vector<Token *> tokens, DatalogProgram* datalogProgram) {
    if (match(TokenType::ID)) {
        Predicate* schemePredicate = new Predicate(tokens[index]->getDescription());
        datalogProgram->setSchemes(schemePredicate);

        //Parse scheme id
        parseId(tokens);
        parseLeftParen(tokens);

        Parameter* temp = parseId(tokens);
        schemePredicate->addParameter(temp);

        parseIdList(tokens, schemePredicate);
        parseRightParen(tokens);
    }
    else {
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseFact(std::vector<Token *> tokens, DatalogProgram* datalogProgram) {
    if (match(TokenType::ID)) {
        Predicate* factPredicate = new Predicate(tokens[index]->getDescription());
        datalogProgram->setFacts(factPredicate);

        //parse fact ID
        parseId(tokens);
        parseLeftParen(tokens);

        Parameter* temp = parseString(tokens);
        factPredicate->addParameter(temp);

        parseStringList(tokens, factPredicate);
        parseRightParen(tokens);
        parsePeriod(tokens);

    }
    else {
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseRule(std::vector<Token *> tokens) {
    if (match(TokenType::ID)) {
        parseHeadPredicate(tokens);
        parseColonDash(tokens);
        parsePredicate(tokens);
        parsePredicateList(tokens);
        parsePeriod(tokens);
    }
    else {
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseQuery(std::vector<Token *> tokens) {
    if(match(TokenType::ID)) {
        parsePredicate(tokens);
        parseQMark(tokens);
    }
    else {
        Token* errToken = tokens[index];
        throw errToken;
    }
}

void Parser::parseHeadPredicate(std::vector<Token *> tokens) {
    if (match(TokenType::ID)) {
        Predicate* head = new Predicate(tokens[index]->getDescription());

        //Parse head predicate ID
        parseId(tokens);
        parseLeftParen(tokens);

        Parameter* temp = parseId(tokens);
        head->addParameter(temp);

        parseIdList(tokens, head);
        parseRightParen(tokens);
    }
}
void Parser::parsePredicate(std::vector<Token *> tokens) {
    Predicate* predicate = new Predicate(tokens[index]->getDescription());

    //parse predicate ID
    parseId(tokens);
    parseLeftParen(tokens);

    Parameter* temp = parseParameter(tokens);
    predicate->addParameter(temp);

    parseParameterList(tokens, predicate);
    parseRightParen(tokens);
}

void Parser::parsePredicateList(std::vector<Token *> tokens) {
    //COMMA == FIRST set of PredicateList
    if(match(TokenType::COMMA)){
        parseComma(tokens);
        parsePredicate(tokens);
        parsePredicateList(tokens);
    }
    //PERIOD == FOLLOW set of PredicateList
    else if(match(TokenType::PERIOD)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseParameterList(std::vector<Token *> tokens, Predicate* p) {
    //COMMA == FIRST set of ParameterList
    if(match(TokenType::COMMA)){
        parseComma(tokens);

        Parameter* temp = parseParameter(tokens);
        p->addParameter(temp);

        parseParameterList(tokens,p);
    }
    //RIGHT_PAREN == FOLLOW set of ParameterList
    else if (match(TokenType::RIGHT_PAREN)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseStringList(std::vector<Token *> tokens, Predicate* p) {
    //COMMA == FIRST set of StringList
    if(match(TokenType::COMMA)) {
        parseComma(tokens);

        Parameter* temp = parseString(tokens);
        p->addParameter(temp);

        parseStringList(tokens, p);
    }
    //RIGHT_PAREN == FOLLOW set of StringList
    else if (match(TokenType::RIGHT_PAREN)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseIdList(std::vector<Token *> tokens, Predicate* p) {
    //COMMA == FIRST set of IdList
    if(match(TokenType::COMMA)) {
        parseComma(tokens);

        Parameter* temp = parseId(tokens);
        p->addParameter(temp);

        parseIdList(tokens, p);
    }
    //RIGHT_PAREN == FOLLOW set of IdList
    else if(match(TokenType::RIGHT_PAREN)){
        //lambda
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
Parameter* Parser::parseParameter(std::vector<Token *> tokens) {
    if(match(TokenType::STRING)){
        Parameter* para = new Parameter(tokens[index]->getDescription());
        parseString(tokens);
        return para;
    }
    else if (match(TokenType::ID)){
        Parameter* para = new Parameter(tokens[index]->getDescription());
        parseId(tokens);
        return para;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}


//Terminal parsing functions
//TODO: maybe implement popping of the front of the vector
//parseTokens.erase(parseTokens.begin());
void Parser::parseSchemes(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::SCHEMES){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseColon(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::COLON){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseFacts(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::FACTS){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseRules(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::RULES){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseQueries(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::QUERIES){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseEndOfFile(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::ENDOFFILE){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
Parameter* Parser::parseId(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::ID){
        Parameter* id = new Parameter(tokens[index]->getDescription());
        index++;
        return id;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseLeftParen(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::LEFT_PAREN){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseRightParen(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::RIGHT_PAREN){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
Parameter* Parser::parseString(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::STRING){
        Parameter* s = new Parameter(tokens[index]->getDescription());
        index++;
        return s;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parsePeriod(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::PERIOD){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseColonDash(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::COLON_DASH){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseQMark(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::Q_MARK){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseComma(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::COMMA){
        index++;
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}