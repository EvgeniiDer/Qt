#include "lexer.h"

Lexer::Lexer(const QString& text) : txt(text), pos{0}
{

}

QString Lexer::get_number()
{
    QString result;
    while(pos < txt.length() && txt[pos].isDigit())
    {
        result = result + txt[pos++];
    }
    return result;
}

Token Lexer::getNextToken()
{
    while(pos < txt.length())
    {
        QChar currentChar = txt[pos];
        if(currentChar.isSpace())
        {
            pos++;
            continue;
        }
        else if(currentChar.isDigit())
        {
            return Token{
                TokenType::Number,
                get_number()
            };
        }
        switch(currentChar.toLatin1())
        {
        case '+':
            pos++;
            return Token{
                TokenType::Plus,
                "+"
            };
        case '-':
            pos++;
                return Token{
                TokenType::Minus,
                "-"
            };
        case '*':
            pos++;
            return Token{
                TokenType::Multiply,
                "*"
            };
        case '/':
            pos++;
            return Token{
                TokenType::Divide,
                "/"
            };
        case '(':
            pos++;
            return Token{
                TokenType::LParen,
                "("
            };
        case ')':
            pos++;
            return Token{
                TokenType::RParen,
                "("
            };
        default:
            throw std::runtime_error("Invalid character");
        }
    }
    return Token{
        TokenType::End,
        ""
    };
}
