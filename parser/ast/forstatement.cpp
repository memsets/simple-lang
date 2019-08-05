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
