#include "binaryexpression.h"

BinaryExpression::BinaryExpression(TokenType operation,
                                   std::shared_ptr<Expression> expr1,
                                   std::shared_ptr<Expression> expr2) : Expression(),
    operation(operation),
    expr1(expr1),
    expr2(expr2)
{
}

BinaryExpression::BinaryExpression()
{
}

std::shared_ptr<Value> BinaryExpression::eval()
{
    std::shared_ptr<Value> value1 = expr1->eval();
    std::shared_ptr<Value> value2 = expr2->eval();

    //TODO: Needs better solution for this condition
    if (std::dynamic_pointer_cast<DoubleValue>(value1) &&
            std::dynamic_pointer_cast<DoubleValue>(value2)) {
        switch (operation) {
        case TokenType::PLUS:
            return std::make_shared<DoubleValue>(value1->asDouble() + value2->asDouble());
        case TokenType::MINUS:
            return std::make_shared<DoubleValue>(value1->asDouble() - value2->asDouble());
        case TokenType::STAR:
            return std::make_shared<DoubleValue>(value1->asDouble() * value2->asDouble());
        case TokenType::SLASH:
            return std::make_shared<DoubleValue>(value1->asDouble() / value2->asDouble());
    //    case TokenType::PER:
    //        return static_cast<int>(expr1->eval()) % static_cast<int>(expr2->eval());
        default:
            return nullptr;
        }
    }
    return nullptr;

}

TokenType BinaryExpression::getOperation() const
{
    return operation;
}

void BinaryExpression::setOperation(const TokenType &value)
{
    operation = value;
}

std::shared_ptr<Expression> BinaryExpression::getExpr2() const
{
    return expr2;
}

void BinaryExpression::setExpr2(const std::shared_ptr<Expression> value)
{
    expr2 = value;
}

std::shared_ptr<Expression> BinaryExpression::getExpr1() const
{
    return expr1;
}

void BinaryExpression::setExpr1(const std::shared_ptr<Expression> value)
{
    expr1 = value;
}


BinaryExpression::~BinaryExpression()
{
}
