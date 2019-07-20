#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include <QtDebug>

#include "expression.h"
#include "../token.h"

class UnaryExpression : public Expression
{
    TokenType operation;
    Expression *expr;
public:
    UnaryExpression(TokenType operation, Expression *expr);
    UnaryExpression();
    double eval() override;
    Expression *getExpr() const;
    void setExpr(Expression *value);
    TokenType getOperation() const;
    void setOperation(const TokenType &value);
    ~UnaryExpression() override;
};

#endif // UNARYEXPRESSION_H
