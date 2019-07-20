#include "binaryexpression.h"

BinaryExpression::BinaryExpression(TokenType operation, Expression *expr1, Expression *expr2) : Expression(),
    operation(operation),
    expr1(expr1),
    expr2(expr2)
{
}

BinaryExpression::BinaryExpression()
{
}

double BinaryExpression::eval()
{
    switch (operation) {
    case TokenType::PLUS:
        return expr1->eval() + expr2->eval();
    case TokenType::MINUS:
        return expr1->eval() - expr2->eval();
    case TokenType::STAR:
        return expr1->eval() * expr2->eval();
    case TokenType::SLASH:
        return expr1->eval() / expr2->eval();
    case TokenType::PER:
        return static_cast<int>(expr1->eval()) % static_cast<int>(expr2->eval());
    default:
        return 0;
    }
}

TokenType BinaryExpression::getOperation() const
{
    return operation;
}

void BinaryExpression::setOperation(const TokenType &value)
{
    operation = value;
}

Expression *BinaryExpression::getExpr2() const
{
    return expr2;
}

void BinaryExpression::setExpr2(Expression *value)
{
    expr2 = value;
}

Expression *BinaryExpression::getExpr1() const
{
    return expr1;
}

void BinaryExpression::setExpr1(Expression *value)
{
    expr1 = value;
}

BinaryExpression::~BinaryExpression()
{
}
