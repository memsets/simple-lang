#include "blockstatement.h"

BlockStatement::BlockStatement(QVector<std::shared_ptr<Statement>> statements) : Statement (),
    statements(statements)
{
}

void BlockStatement::exec()
{
    for (auto statement : statements) {
        statement->exec();
    }
}

BlockStatement::~BlockStatement()
{
}
