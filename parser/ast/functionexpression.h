#ifndef FUNCTIONEXPRESSION_H
#define FUNCTIONEXPRESSION_H

#include <QString>
#include <QVector>
#include <memory>

#include "../lib/value.h"
#include "expression.h"
#include "../lib/functioncontainer.h"
#include "../lib/userfunction.h"
#include "../lib/variablecontainer.h"


class FunctionExpression : public Expression
{
    QString name;
    QVector<std::shared_ptr<Expression>> arguments;
public:
    FunctionExpression(const QString &name,
                       const QVector<std::shared_ptr<Expression>> &arguments);
    FunctionExpression();
    std::shared_ptr<Value> eval() override;
    QString getName() const;
    void setName(const QString &value);
    QVector<std::shared_ptr<Expression> > getArguments() const;
    void setArguments(const QVector<std::shared_ptr<Expression> > &value);
};

#endif // FUNCTIONEXPRESSION_H
