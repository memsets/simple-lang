#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include <QString>
#include <QVector>
#include <memory>

#include "../lib/variablecontainer.h"
#include "expression.h"
#include "../lib/arrayvalue.h"

class ArrayExpression : public Expression
{
    QString name;
    std::shared_ptr<Expression> expression;
public:
    ArrayExpression(QString name, std::shared_ptr<Expression> expression);
    std::shared_ptr<Value> eval() override;
};

#endif // ARRAYEXPRESSION_H
