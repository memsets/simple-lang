#include "functionstatement.h"

FunctionStatement::FunctionStatement(QString name, QVector<std::shared_ptr<Expression>> args) : Statement (),
    name(name),
    args(args)
{
}

void FunctionStatement::exec()
{
    QVector<std::shared_ptr<Value>> values;
    for (auto &arg : args) {
        values.append(arg->eval());
    }
    FunctionContainer::get(name)->exec(values);
}
