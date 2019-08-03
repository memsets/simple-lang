#include "returnstatement.h"

std::shared_ptr<Expression> ReturnStatement::getExpression() const
{
    return expression;
}

void ReturnStatement::setExpression(const std::shared_ptr<Expression> &value)
{
    expression = value;
}

ReturnStatement::ReturnStatement(std::shared_ptr<Expression> expression) : Statement (),
    expression(expression)
{
}

void ReturnStatement::exec()
{
    throw std::make_shared<ReturnStatement>(*this);
}
