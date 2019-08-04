#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include <QString>
#include <QVector>
#include <memory>
#include <typeinfo>

#include "../lib/variablecontainer.h"
#include "expression.h"
#include "../lib/arrayvalue.h"

class ArrayExpression : public Expression
{
    QString name;
    QVector<std::shared_ptr<Expression>> indices;
public:
    ArrayExpression(QString name, QVector<std::shared_ptr<Expression>> indices);
    std::shared_ptr<Value> eval() override;
};

#endif // ARRAYEXPRESSION_H
