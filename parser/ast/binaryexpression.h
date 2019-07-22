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
    std::shared_ptr<Expression> expr1;
    std::shared_ptr<Expression> expr2;
public:
    BinaryExpression(TokenType operation, std::shared_ptr<Expression> expr1,
                     std::shared_ptr<Expression> expr2);
    BinaryExpression();
    double eval() override;
    TokenType getOperation() const;
    void setOperation(const TokenType &value);
    ~BinaryExpression() override;
    std::shared_ptr<Expression> getExpr2() const;
    void setExpr2(const std::shared_ptr<Expression> value);
    std::shared_ptr<Expression> getExpr1() const;
    void setExpr1(const std::shared_ptr<Expression> value);
};

#endif // BINARYEXPRESSION_H
