#ifndef VARIABLEEXPRESSION_H
#define VARIABLEEXPRESSION_H

#include <QString>

#include "expression.h"
#include "../lib/variablecontainer.h"

class VariableExpression : public Expression
{
    QString name;
public:
    VariableExpression(QString name);
    double eval() override;
    QString getName() const;
    void setName(const QString &value);
};

#endif // VARIABLEEXPRESSION_H
