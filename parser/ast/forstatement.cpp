#include "forstatement.h"

ForStatement::ForStatement(std::shared_ptr<Statement> initialization,
                           std::shared_ptr<Expression> condition,
                           std::shared_ptr<Statement> increment,
                           std::shared_ptr<Statement> forStatement) : Statement (),
    initialization(initialization),
    condition(condition),
    increment(increment),
    forStatement(forStatement)
{
}

ForStatement::ForStatement()
{
}

void ForStatement::exec()
{
    VariableContainer::push();
    for (initialization->exec(); condition->eval()->asBoolean() != false; increment->exec()) {
        try {
            forStatement->exec();
        } catch (ContinueStatement) {
            continue;
        } catch (BreakStatement) {
            break;
        }
    }
    VariableContainer::pop();
}

std::shared_ptr<Statement> ForStatement::getInitialization() const
{
    return initialization;
}

void ForStatement::setInitialization(const std::shared_ptr<Statement> &value)
{
    initialization = value;
}

std::shared_ptr<Expression> ForStatement::getCondition() const
{
    return condition;
}

void ForStatement::setCondition(const std::shared_ptr<Expression> &value)
{
    condition = value;
}

std::shared_ptr<Statement> ForStatement::getIncrement() const
{
    return increment;
}

void ForStatement::setIncrement(const std::shared_ptr<Statement> &value)
{
    increment = value;
}

std::shared_ptr<Statement> ForStatement::getForStatement() const
{
    return forStatement;
}

void ForStatement::setForStatement(const std::shared_ptr<Statement> &value)
{
    forStatement = value;
}
