#include "variablecontainer.h"

QHash<QString, double> VariableContainer::container;

VariableContainer::VariableContainer()
{
}

void VariableContainer::set(QString name, double value)
{
    container[name] = value;
}

double VariableContainer::get(QString name)
{
    return container[name];
}

bool VariableContainer::isExists(QString name)
{
    if (container.contains(name)) {
        return true;
    }
    return false;
}
