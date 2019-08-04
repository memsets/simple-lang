#ifndef FUNCTIONDEFINESTATEMENT_H
#define FUNCTIONDEFINESTATEMENT_H

#include <QString>
#include <QVector>

#include "statement.h"
#include "expression.h"
#include "../lib/functioncontainer.h"
#include "../lib/userfunction.h"

class FunctionDefineStatement : public Statement
{
    QString name;
    QVector<QString> argNames;
    std::shared_ptr<Statement> body;
public:
    FunctionDefineStatement(QString name, QVector<QString> argNames, std::shared_ptr<Statement> body);
    void exec() override;
};

#endif // FUNCTIONDEFINESTATEMENT_H
