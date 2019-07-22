#include "variableexpression.h"

QString VariableExpression::getName() const
{
    return name;
}

void VariableExpression::setName(const QString &value)
{
    name = value;
}

VariableExpression::VariableExpression(QString name) : Expression(), name(name)
{
}

double VariableExpression::eval()
{
    if (!VariableContainer::isExists(name)) {
        qFatal("Variable is not exist");
    }
    return VariableContainer::get(name);
}