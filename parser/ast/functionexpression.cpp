#include "functionexpression.h"

FunctionExpression::FunctionExpression(QString name, QVector<std::shared_ptr<Expression>> args) : Expression (),
    name(name),
    args(args)
{
}

std::shared_ptr<Value> FunctionExpression::eval()
{
    QVector<std::shared_ptr<Value>> values;

    for (auto &expr : args) {
        values.append(expr->eval());
    }

    if (!FunctionContainer::isExists(name)) {
        qFatal("Unknown function");
    }


    return FunctionContainer::get(name)->exec(values);
}
