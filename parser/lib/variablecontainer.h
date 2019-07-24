#ifndef VARIABLECONTAINER_H
#define VARIABLECONTAINER_H

#include <QHash>
#include <QDebug>
#include <QString>
#include <QChar>
#include <QStack>
#include <memory>

#include "value.h"

class VariableContainer
{
    static QStack<QHash<QString, std::shared_ptr<Value> >> stack;
    static QHash<QString, std::shared_ptr<Value> > container;
public:
    VariableContainer();
    static void set(QString name, std::shared_ptr<Value> value);
    static std::shared_ptr<Value>  get(QString name);
    static bool isExists(QString name);
    static void push();
    static void pop();
};

//extern VariableContainer variables;

#endif // VARIABLECONTAINER_H
