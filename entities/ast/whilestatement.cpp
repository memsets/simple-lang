#include "whilestatement.h"

WhileStatement::WhileStatement(std::shared_ptr<Expression> condition,
                               std::shared_ptr<Statement> whileStatement) : Statement (),
    condition(condition),
    whileStatement(whileStatement)
{
}

void WhileStatement::exec()
{
    VariableContainer::push();
    while (condition->eval()->asBoolean()) {
        try {
            whileStatement->exec();
        } catch (ContinueStatement) {
            continue;
        } catch (BreakStatement) {
            break;
        }
    }
    VariableContainer::pop();
}

WhileStatement::WhileStatement()
{
}

std::shared_ptr<Expression> WhileStatement::getCondition() const
{
    return condition;
}

void WhileStatement::setCondition(const std::shared_ptr<Expression> &value)
{
    condition = value;
}

std::shared_ptr<Statement> WhileStatement::getWhileStatement() const
{
    return whileStatement;
}

void WhileStatement::setWhileStatement(const std::shared_ptr<Statement> &value)
{
    whileStatement = value;
}
