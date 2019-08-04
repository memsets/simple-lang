#include "blockstatement.h"

BlockStatement::BlockStatement(QVector<std::shared_ptr<Statement>> statements) : Statement (),
    statements(statements)
{
}

void BlockStatement::exec()
{
    VariableContainer::push();
    for (auto statement : statements) {
        statement->exec();
    }
    VariableContainer::pop();
}

BlockStatement::~BlockStatement()
{
}
