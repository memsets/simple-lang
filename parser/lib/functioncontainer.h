#ifndef FUNCTIONCONTAINER_H
#define FUNCTIONCONTAINER_H

#include <QVector>
#include <cmath>
#include <memory>
#include <QHash>
#include <QString>
#include <QDebug>

#include "function.h"
#include "doublevalue.h"

class _native_sin : public Function
{
public:
    std::shared_ptr<Value> exec(QVector<std::shared_ptr<Value>> values) override
    {
        return std::make_shared<DoubleValue>(DoubleValue(sin(values[0]->asDouble())));
    }
};

class _native_cos : public Function
{
public:
    std::shared_ptr<Value> exec(QVector<std::shared_ptr<Value>> values) override
    {
        return std::make_shared<DoubleValue>(DoubleValue(cos(values[0]->asDouble())));
    }
};

class _native_print : public Function
{
public:
    std::shared_ptr<Value> exec(QVector<std::shared_ptr<Value>> values) override
    {
        for (auto &value : values) {
            qInfo() << value->asString();
        }
        return std::make_shared<DoubleValue>(DoubleValue(0.0));
    }
};

class FunctionContainer
{
    static QHash<QString, std::shared_ptr<Function>> container;
public:
    FunctionContainer();
    static void set(QString name, std::shared_ptr<Function> value);
    static std::shared_ptr<Function>  get(QString name);
    static bool isExists(QString name);
};

#endif // FUNCTIONCONTAINER_H
