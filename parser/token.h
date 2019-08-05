#ifndef TOKEN_H
#define TOKEN_H

#include <QString>

enum class TokenType
{
    NUM, TEXT, STAR, SLASH, MINUS, PLUS, PER,
    LPAREN, RPAREN, WORD, EQ,
    LBRACE, RBRACE, LBRACKET, RBRACKET, COMMA, SEMICOLON,

    GT, LT, EQEQ, NOTEQ, GTEQ, LTEQ,
    TRUE, FALSE, IF, ELSE, NOT, AND, OR, FUNCTION, RETURN,
    DO, WHILE, FOR, BREAK, CONTINUE,
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
