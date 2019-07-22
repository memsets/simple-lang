#ifndef TOKEN_H
#define TOKEN_H

#include <QString>

enum class TokenType
{
    NUM, STAR, SLASH, MINUS, PLUS, PER,
    LPAREN, RPAREN, WORD, EQ,

    END
};

class Token
{
    TokenType type;
    QString text;
public:
    Token(TokenType type, QString text);
    Token();
    TokenType getType() const;
    void setType(const TokenType &value);
    QString getText() const;
    void setText(const QString &value);
};

#endif // TOKEN_H
