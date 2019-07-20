#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QString>
#include <QDebug>

#include "token.h"
#include "ast/expression.h"
#include "ast/binaryexpression.h"
#include "ast/numberexpression.h"
#include "ast/unaryexpression.h"

class Parser
{
    QVector<Token> tokens;
    int pos, size;

public:
    Parser(QVector<Token> tokens);
    Expression *expression();
    Expression *additive();
    Expression *multiplicative();
    Expression *unary();
    Expression *primary();
    Token peek(const int relativePosition) const;
    bool match(TokenType type);
};

#endif // PARSER_H
