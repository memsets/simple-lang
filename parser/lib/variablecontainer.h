#ifndef VARIABLECONTAINER_H
#define VARIABLECONTAINER_H

#include <QHash>
#include <QDebug>
#include <QString>
#include <QChar>

class VariableContainer
{
    static QHash<QString, double> container;
public:
    VariableContainer();
    static void set(QString name, double value);
    static double get(QString name);
    static bool isExists(QString name);
};

//extern VariableContainer variables;

#endif // VARIABLECONTAINER_H
