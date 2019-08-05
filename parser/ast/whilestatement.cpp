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
