#include "Parser.h"

bool Parser::match(TokenType tokType) {
    if (parseTokens[index]->getType() == tokType){
        //TODO: implement popping of the front of the vector in a different ParseTerminal function
        //parseTokens.erase(parseTokens.begin());
        return true;
    }
    else {
        Token* errTok = parseTokens[index+1];
        throw errTok;
    }
}

DatalogProgram Parser::Parse(std::vector<Token *> input) {
    try {
        parseDatalogProgram(parseTokens);
    } catch (Token* error) {
        std::cout << "Failure!" << std::endl;
        std::cout << "  " << *error;
    }
    std::cout << "Success!" << std::endl;
}

//Non-Terminal parsing functions
void Parser::parseDatalogProgram(std::vector<Token*> tokens) {
    //SCHEMES == First set of DatalogProgram
    if (match(TokenType::SCHEMES)) {
        match(TokenType::SCHEMES);
        match(TokenType::COLON);
        parseScheme(tokens);
        parseSchemeList(tokens);
        match(TokenType::FACTS);
        match(TokenType::COLON);
        parseFactList(tokens);
        match(TokenType::RULES);
        match(TokenType::COLON);
        parseRuleList(tokens);
        match(TokenType::QUERIES);
        match(TokenType::COLON);
        parseQuery(tokens);
        parseQueryList(tokens);
        match(TokenType::ENDOFFILE);
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}
void Parser::parseSchemeList(std::vector<Token*> tokens) {
    //ID == first set of SchemeList
    if(match(TokenType::ID)){
        parseScheme(tokens);
        parseSchemeList(tokens);
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
void Parser::parseFactList(std::vector<Token *> tokens) {
    //ID == FIRST set of FactList
    if(match(TokenType::ID)){
        parseFact(tokens);
        parseFactList(tokens);
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
void Parser::parseScheme(std::vector<Token *> tokens) {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    parseIdList(tokens);
    match(TokenType::RIGHT_PAREN);
}
void Parser::parseFact(std::vector<Token *> tokens) {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::STRING);
    parseStringList(tokens);
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);
}
void Parser::parseRule(std::vector<Token *> tokens) {
    parseHeadPredicate(tokens);
    match(TokenType::COLON_DASH);
    parsePredicate(tokens);
    parsePredicateList(tokens);
    match(TokenType::PERIOD);
}
void Parser::parseQuery(std::vector<Token *> tokens) {
    parsePredicate(tokens);
    match(TokenType::Q_MARK);
}
void Parser::parseHeadPredicate(std::vector<Token *> tokens) {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    parseIdList(tokens);
    match(TokenType::RIGHT_PAREN);
}
void Parser::parsePredicate(std::vector<Token *> tokens) {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    parseParameter(tokens);
    parseParameterList(tokens);
    match(TokenType::RIGHT_PAREN);
}
void Parser::parsePredicateList(std::vector<Token *> tokens) {
    //COMMA == FIRST set of PredicateList
    if(match(TokenType::COMMA)){
        match(TokenType::COMMA);
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
void Parser::parseParameterList(std::vector<Token *> tokens) {
    //COMMA == FIRST set of ParameterList
    if(match(TokenType::COMMA)){
        match(TokenType::COMMA);
        parseParameter(tokens);
        parseParameterList(tokens);
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
void Parser::parseStringList(std::vector<Token *> tokens) {
    //COMMA == FIRST set of StringList
    if(match(TokenType::COMMA)) {
        match(TokenType::COMMA);
        match(TokenType::STRING);
        parseStringList(tokens);
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
void Parser::parseIdList(std::vector<Token *> tokens) {
    //COMMA == FIRST set of IdList
    if(match(TokenType::COMMA)) {
        match(TokenType::COMMA);
        match(TokenType::ID);
        parseIdList(tokens);
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
void Parser::parseParameter(std::vector<Token *> tokens) {
    if(match(TokenType::STRING)){
        match(TokenType::STRING);
    }
    else if (match(TokenType::ID)){
        match(TokenType::ID);
    }
    else{
        Token* errToken = tokens[index];
        throw errToken;
    }
}


//Terminal parsing functions
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
void Parser::parseId(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::ID){
        index++;
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
void Parser::parseString(std::vector<Token*> tokens){
    if (tokens[index]->getType() == TokenType::STRING){
        index++;
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