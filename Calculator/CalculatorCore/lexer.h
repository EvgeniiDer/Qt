#ifndef LEXER_H
#define LEXER_H


#include<QString>
#include<QVector>
#include<QChar>
#include<stdexcept>

enum class TokenType{
    Number,
    Plus,
    Minus,
    Multiply,
    Divide,
    LParen,
    RParen,
    End
};

struct Token{
    TokenType type;
    QString value;
};

class Lexer
{
private:

    QString txt;
    size_t pos;
    QString get_number();
public:
    explicit Lexer(const QString& text);
    Token getNextToken();
};

#endif // LEXER_H
