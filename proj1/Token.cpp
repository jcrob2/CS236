#include "Token.h"
#include <sstream>

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->line = line;

}

std::string Token::toString() const {
    std::string typeOfToken;
    std::ostringstream output;
    switch (Token::type) {
        case TokenType::COLON:
            typeOfToken = "COLON";
            break;
        case TokenType::COLON_DASH:
            typeOfToken = "COLON_DASH";
            break;
        case TokenType::COMMENT:
            typeOfToken = "COMMENT";
            break;
        case TokenType::COMMA:
            typeOfToken = "COMMA";
            break;
        case TokenType::PERIOD:
            typeOfToken = "PERIOD";
            break;
        case TokenType::Q_MARK:
            typeOfToken = "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            typeOfToken = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            typeOfToken = "RIGHT_PAREN";
            break;
        case TokenType::MULTIPLY:
            typeOfToken = "MULTIPLY";
            break;
        case TokenType::ADD:
            typeOfToken = "ADD";
            break;
        case TokenType::SCHEMES:
            typeOfToken = "SCHEMES";
            break;
        case TokenType::FACTS:
            typeOfToken = "FACTS";
            break;
        case TokenType::RULES:
            typeOfToken = "RULES";
            break;
        case TokenType::QUERIES:
            typeOfToken = "QUERIES";
            break;
        case TokenType::ID:
            typeOfToken = "ID";
            break;
        case TokenType::STRING:
            typeOfToken = "STRING";
            break;
        case TokenType::UNDEFINED:
            typeOfToken = "UNDEFINED";
            break;
        case TokenType::ENDOFFILE:
            typeOfToken = "EOF";
            break;
    }

    output << "(" << typeOfToken << ",\"" << description << "\"," << line << ")" << std::endl;

    return output.str();
}
