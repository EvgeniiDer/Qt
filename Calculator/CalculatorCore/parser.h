#ifndef PARSER_H
#define PARSER_H

#include"lexer.h"

class Parser
{
private:
    Lexer& lexer;
    Token currentToken;
    void eat(TokenType type);
    double expression();
    double term();
    double factor();
public:
    explicit Parser(Lexer& lexer);
    double parse();
};

#endif // PARSER_H
