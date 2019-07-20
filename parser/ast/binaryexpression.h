#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include <QChar>
#include <iostream>
#include <memory>

#include "../token.h"
#include "expression.h"


class BinaryExpression : public Expression
{
    TokenType operation;
    Expression *expr1;
    Expression *expr2;
public:
    BinaryExpression(TokenType operation, Expression *expr1, Expression *expr2);
    BinaryExpression();
    double eval() override;
    TokenType getOperation() const;
    void setOperation(const TokenType &value);
    ~BinaryExpression() override;
    Expression *getExpr2() const;
    void setExpr2(Expression *value);
    Expression *getExpr1() const;
    void setExpr1(Expression *value);
};

#endif // BINARYEXPRESSION_H
