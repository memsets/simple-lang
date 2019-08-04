#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include <memory>
#include <QString>
#include <QVector>

#include "expression.h"
#include "statement.h"
#include "../lib/variablecontainer.h"

class BlockStatement : public Statement
{
    QVector<std::shared_ptr<Statement>> statements;
public:
    BlockStatement(QVector<std::shared_ptr<Statement>> statements);
    void exec() override;
    ~BlockStatement() override;
};

#endif // BLOCKSTATEMENT_H
