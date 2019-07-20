#include "unaryexpression.h"

UnaryExpression::UnaryExpression(TokenType operation, Expression *expr) : Expression(),
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

Expression *UnaryExpression::getExpr() const
{
    return expr;
}

void UnaryExpression::setExpr(Expression *value)
{
    expr = value;
}

TokenType UnaryExpression::getOperation() const
{
    return operation;
}

void UnaryExpression::setOperation(const TokenType &value)
{
    operation = value;
}

UnaryExpression::~UnaryExpression()
{
    delete expr;
}
