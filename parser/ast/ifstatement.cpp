#include "ifstatement.h"

IfStatement::IfStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> ifStatement,
                         std::shared_ptr<Statement> elseStatement) : Statement (),
    condition(condition),
    ifStatement(ifStatement),
    elseStatement(elseStatement)
{
}

IfStatement::IfStatement()
{
}

void IfStatement::exec()
{
    bool cond = condition->eval()->asBoolean();

    if (cond) {
        ifStatement->exec();
    } else if (elseStatement != nullptr) {
        elseStatement->exec();
    }
}

std::shared_ptr<Expression> IfStatement::getCondition() const
{
    return condition;
}

void IfStatement::setCondition(const std::shared_ptr<Expression> &value)
{
    condition = value;
}

std::shared_ptr<Statement> IfStatement::getIfStatement() const
{
    return ifStatement;
}

void IfStatement::setIfStatement(const std::shared_ptr<Statement> &value)
{
    ifStatement = value;
}

std::shared_ptr<Statement> IfStatement::getElseStatement() const
{
    return elseStatement;
}

void IfStatement::setElseStatement(const std::shared_ptr<Statement> &value)
{
    elseStatement = value;
}
