#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include <QtDebug>
#include <memory>

#include "expression.h"
#include "../token.h"

class UnaryExpression : public Expression
{
    TokenType operation;
    std::shared_ptr<Expression> expr;
public:
    UnaryExpression(TokenType operation, std::shared_ptr<Expression> expr);
    UnaryExpression();
    double eval() override;
    TokenType getOperation() const;
    void setOperation(const TokenType &value);
    ~UnaryExpression() override;
    std::shared_ptr<Expression> getExpr() const;
    void setExpr(const std::shared_ptr<Expression> value);
};

#endif // UNARYEXPRESSION_H
