#ifndef BLOCKSTATEMENT_H
#define BLOCKSTATEMENT_H

#include <memory>
#include <QString>
#include <QVector>

#include "expression.h"
#include "statement.h"
#include "../../entities/variablecontainer.h"

class BlockStatement : public Statement
{
    QVector<std::shared_ptr<Statement>> statements;
public:
    BlockStatement(QVector<std::shared_ptr<Statement>> statements);
    BlockStatement();
    void exec() override;
    ~BlockStatement() override;
    QVector<std::shared_ptr<Statement> > getStatements() const;
    void setStatements(const QVector<std::shared_ptr<Statement> > &value);
};

#endif // BLOCKSTATEMENT_H
