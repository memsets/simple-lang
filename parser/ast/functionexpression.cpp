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

    std::shared_ptr<Function> func = FunctionContainer::get(name);

    if (auto f = std::dynamic_pointer_cast<UserFunction>(func)) {
        for (int i = 0; i < args.size(); i++) {
            VariableContainer::set(f->getArgNames()[i], args[i]->eval());
        }
    }

    return FunctionContainer::get(name)->exec(values);
}
