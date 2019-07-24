#include "variablecontainer.h"

QStack<QHash<QString, std::shared_ptr<Value>>> VariableContainer::stack;

QHash<QString, std::shared_ptr<Value>> VariableContainer::container;

VariableContainer::VariableContainer()
{
}

void VariableContainer::set(QString name, std::shared_ptr<Value> value)
{
    container[name] = value;
}

std::shared_ptr<Value>  VariableContainer::get(QString name)
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

void VariableContainer::push()
{
    stack.push(container);
}

void VariableContainer::pop()
{
    container = stack.pop();
}
