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
    std::shared_ptr<Value> value = expr->eval();

    if (std::dynamic_pointer_cast<DoubleValue>(value)) {
        switch (operation) {
        case TokenType::MINUS:
            return std::make_shared<DoubleValue>(-value->asDouble());
        case TokenType::PLUS:
            return std::make_shared<DoubleValue>(value->asDouble());
        default:
            qFatal("Unknown unary operation");
        }
    } else if (std::dynamic_pointer_cast<BooleanValue>(value)) {
        switch (operation) {
        case TokenType::NOT:
            return std::make_shared<BooleanValue>(!value->asBoolean());
        default:
            qFatal("Unknown unary operation");
        }
    }

    qFatal("Unknown operands");
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
