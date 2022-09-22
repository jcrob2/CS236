#include "Token.h"
#include <sstream>

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
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
