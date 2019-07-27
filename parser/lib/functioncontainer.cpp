#include "functioncontainer.h"

QHash<QString, std::shared_ptr<Function>> FunctionContainer::container;

FunctionContainer::FunctionContainer()
{
}

void FunctionContainer::set(QString name, std::shared_ptr<Function> value)
{
    container[name] = value;
}

std::shared_ptr<Function> FunctionContainer::get(QString name)
{
    return container[name];
}

bool FunctionContainer::isExists(QString name)
{
    if (container.contains(name)) {
        return true;
    }
    return false;
}
