#include "unaryexpression.h"

UnaryExpression::UnaryExpression(TokenType operation, std::shared_ptr<Expression> expr) : Expression(),
    operation(operation),
    expr(expr)
{
}

UnaryExpression::UnaryExpression()
{
}

double UnaryExpression::eval()
{
    switch (operation) {
    case TokenType::MINUS:
        return -expr->eval();
    case TokenType::PLUS:
        return expr->eval();
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
