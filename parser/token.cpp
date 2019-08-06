#include "token.h"

Token::Token(const TokenType &type, const QString &text) : type(type), text(text)
{
}

Token::Token()
{
}

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
