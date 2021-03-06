#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include <QChar>
#include <iostream>
#include <memory>
#include <typeinfo>

#include "../../parsing/token.h"
#include "expression.h"
#include "../../entities/value.h"
#include "valueexpression.h"
#include "../../entities/doublevalue.h"
#include "../../entities/stringvalue.h"
#include "../../entities/booleanvalue.h"

class BinaryExpression : public Expression
{
    TokenType operation;
    std::shared_ptr<Expression> expr1;
    std::shared_ptr<Expression> expr2;
public:
    BinaryExpression(const TokenType &operation, std::shared_ptr<Expression> expr1,
                     std::shared_ptr<Expression> expr2);
    BinaryExpression();

    std::shared_ptr<Value> eval() override;

    TokenType getOperation() const;
    void setOperation(const TokenType &value);
    std::shared_ptr<Expression> getExpr2() const;
    void setExpr2(const std::shared_ptr<Expression> value);
    std::shared_ptr<Expression> getExpr1() const;
    void setExpr1(const std::shared_ptr<Expression> value);

    ~BinaryExpression() override;
};

#endif // BINARYEXPRESSION_H
