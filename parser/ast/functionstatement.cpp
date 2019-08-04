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
    std::shared_ptr<Function> func = FunctionContainer::get(name);

    if (auto f = std::dynamic_pointer_cast<UserFunction>(func)) {
        for (int i = 0; i < args.size(); i++) {
            VariableContainer::set(f->getArgNames()[i], args[i]->eval());
        }
    }

    func->exec(values);
}
