#ifndef VARIABLECONTAINER_H
#define VARIABLECONTAINER_H

#include <QHash>
#include <QDebug>
#include <QString>
#include <QChar>
#include <QStack>

class VariableContainer
{
    static QStack<QHash<QString, double>> stack;
    static QHash<QString, double> container;
public:
    VariableContainer();
    static void set(QString name, double value);
    static double get(QString name);
    static bool isExists(QString name);
    static void push();
    static void pop();
};

//extern VariableContainer variables;

#endif // VARIABLECONTAINER_H
