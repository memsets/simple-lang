#include "unaryexpression.h"

UnaryExpression::UnaryExpression(TokenType operation, std::shared_ptr<Expression> expr) : Expression(),
    operation(operation),
    expr(expr)
{
}

UnaryExpression::UnaryExpression()
{
}

std::shared_ptr<Value> UnaryExpression::eval()
{
    const double number = expr->eval()->asDouble();
    switch (operation) {
    case TokenType::MINUS:
        return std::make_shared<DoubleValue>(-number);
    case TokenType::PLUS:
        return std::make_shared<DoubleValue>(number);
    default:
        qFatal("Unknown this unary operation");
    }
}

TokenType UnaryExpression::getOperation() const
{
    return operation;
}

void UnaryExpression::setOperation(const TokenType &value)
{
    operation = value;
}

std::shared_ptr<Expression> UnaryExpression::getExpr() const
{
    return expr;
}

void UnaryExpression::setExpr(const std::shared_ptr<Expression> value)
{
    expr = value;
}

UnaryExpression::~UnaryExpression()
{
}
