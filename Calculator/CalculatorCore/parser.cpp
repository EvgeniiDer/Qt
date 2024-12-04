#include "parser.h"

Parser::Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.getNextToken()) {}
double Parser::parse()
{
    return expression();
}

double Parser::expression()
{
    double result = term();
    while (true) {
        switch (currentToken.type) {
        case TokenType::Plus:
            eat(TokenType::Plus);
            result += term();
            break;
        case TokenType::Minus:
            eat(TokenType::Minus);
            result -= term();
            break;
        default:
            return result; // Выход из цикла, если нет больше операторов
        }
    }
}

double Parser::term()
{
    double result = factor();
    while (true) {
        switch (currentToken.type) {
        case TokenType::Multiply:
            eat(TokenType::Multiply);
            result *= factor();
            break;
        case TokenType::Divide:
            eat(TokenType::Divide);
            result /= factor();
            break;
        default:
            return result; // Выход из цикла, если нет больше операторов
        }
    }
}


double Parser::factor()
{
    if (currentToken.type == TokenType::Number) {
        double value = currentToken.value.toDouble();
        eat(TokenType::Number);
        return value;
    } else if (currentToken.type == TokenType::LParen) {
        eat(TokenType::LParen);
        double result = expression();
        eat(TokenType::RParen);
        return result;
    }
    throw std::runtime_error("Invalid syntax");
}
void Parser::eat(TokenType type)
{
    if (currentToken.type == type) {
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Invalid syntax");
    }
}
