#include "ifstatement.h"

IfStatement::IfStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> ifStatement,
                         std::shared_ptr<Statement> elseStatement) : Statement (),
    condition(condition),
    ifStatement(ifStatement),
    elseStatement(elseStatement)
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
