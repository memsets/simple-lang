#ifndef ARRAYVALUE_H
#define ARRAYVALUE_H

#include <QString>
#include <QVector>
#include <iostream>
#include <memory>

#include "value.h"


class ArrayValue : public Value
{
    QVector<std::shared_ptr<Value>> values;
public:
    ArrayValue(QVector<std::shared_ptr<Value>> values);
    bool asBoolean() override;
    QString asString() override;
    double asDouble() override;
    std::shared_ptr<Value> index(std::shared_ptr<Value> index);

};

#endif // ARRAYVALUE_H
