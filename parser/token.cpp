#include "token.h"

TokenType Token::getType() const
{
    return type;
}

void Token::setType(const TokenType &value)
{
    type = value;
}

QString Token::getText() const
{
    return text;
}

void Token::setText(const QString &value)
{
    text = value;
}

Token::Token(TokenType type, QString text) : type(type), text(text)
{
}

Token::Token()
{
}
