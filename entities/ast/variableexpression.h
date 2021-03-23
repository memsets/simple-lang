#ifndef VARIABLEEXPRESSION_H
#define VARIABLEEXPRESSION_H

#include <QString>

#include "expression.h"
#include "../../entities/variablecontainer.h"
#include "../../entities/value.h"

class VariableExpression : public Expression
{
    QString name;
public:
    VariableExpression(const QString &name);
    VariableExpression();
    std::shared_ptr<Value> eval() override;
    QString getName() const;
    void setName(const QString &value);
};

#endif // VARIABLEEXPRESSION_H
