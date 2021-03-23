#ifndef FUNCTIONSTATEMENT_H
#define FUNCTIONSTATEMENT_H

#include <QString>
#include <QVector>
#include <memory>

#include "../../entities/functioncontainer.h"
#include "expression.h"
#include "statement.h"
#include "../../entities/function.h"
#include "../../entities/userfunction.h"
#include "../../entities/variablecontainer.h"


class FunctionStatement : public Statement
{
    QString name;
    QVector<std::shared_ptr<Expression>> arguments;
public:
    FunctionStatement(const QString &name, const QVector<std::shared_ptr<Expression>> &arguments);
    FunctionStatement();
    void exec() override;
    QString getName() const;
    void setName(const QString &value);
    QVector<std::shared_ptr<Expression> > getArguments() const;
    void setArguments(const QVector<std::shared_ptr<Expression> > &value);
};

#endif // FUNCTIONSTATEMENT_H
