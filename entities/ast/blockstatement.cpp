#include "blockstatement.h"

BlockStatement::BlockStatement(QVector<std::shared_ptr<Statement>> statements) : Statement (),
    statements(statements)
{
}

BlockStatement::BlockStatement()
{
}

void BlockStatement::exec()
{
    for (auto &statement : statements) {
        statement->exec();
    }
}

QVector<std::shared_ptr<Statement> > BlockStatement::getStatements() const
{
    return statements;
}

void BlockStatement::setStatements(const QVector<std::shared_ptr<Statement> > &value)
{
    statements = value;
}

BlockStatement::~BlockStatement()
{
}
