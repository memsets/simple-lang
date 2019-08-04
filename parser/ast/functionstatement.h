#ifndef FUNCTIONSTATEMENT_H
#define FUNCTIONSTATEMENT_H

#include <QString>
#include <QVector>
#include <memory>

#include "../lib/functioncontainer.h"
#include "expression.h"
#include "statement.h"
#include "../lib/function.h"
#include "../lib/userfunction.h"
#include "../lib/variablecontainer.h"


class FunctionStatement : public Statement
{
    QString name;
    QVector<std::shared_ptr<Expression>> args;
public:
    FunctionStatement(QString name, QVector<std::shared_ptr<Expression>> args);
    void exec() override;
};

#endif // FUNCTIONSTATEMENT_H
