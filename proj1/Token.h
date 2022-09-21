#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    // TODO: add the other types of tokens
    UNDEFINED,
    ENDOFFILE
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType type;
    std::string description;
    int line;

public:
    Token(TokenType type, std::string description, int line);

    std::string toString() const;

    friend std::ostream& operator<< (std::ostream& os, const Token& token){
        os << token.toString();
        return os;
    }
    // TODO: add other needed methods
};

#endif // TOKEN_H

