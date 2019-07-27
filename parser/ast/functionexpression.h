#ifndef FUNCTIONEXPRESSION_H
#define FUNCTIONEXPRESSION_H

#include <QString>
#include <QVector>
#include <memory>

#include "../lib/value.h"
#include "expression.h"
#include "../lib/functioncontainer.h"


class FunctionExpression : public Expression
{
    QString name;
    QVector<std::shared_ptr<Expression>> args;
public:
    FunctionExpression(QString name, QVector<std::shared_ptr<Expression>> args);
    std::shared_ptr<Value> eval() override;
};

#endif // FUNCTIONEXPRESSION_H
