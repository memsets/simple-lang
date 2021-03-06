#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include <QtDebug>
#include <memory>
#include <typeinfo>

#include "expression.h"
#include "../../parsing/token.h"
#include "../../entities/value.h"
#include "../../entities/doublevalue.h"
#include "../../entities/booleanvalue.h"

class UnaryExpression : public Expression
{
    TokenType operation;
    std::shared_ptr<Expression> expr;
public:
    UnaryExpression(TokenType operation, std::shared_ptr<Expression> expr);
    UnaryExpression();
    std::shared_ptr<Value> eval() override;
    TokenType getOperation() const;
    void setOperation(const TokenType &value);
    ~UnaryExpression() override;
    std::shared_ptr<Expression> getExpr() const;
    void setExpr(const std::shared_ptr<Expression> value);
};

#endif // UNARYEXPRESSION_H
