#include "variableexpression.h"

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
