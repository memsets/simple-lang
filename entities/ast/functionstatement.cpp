#include "functionstatement.h"

FunctionStatement::FunctionStatement(const QString &name,
                                     const QVector<std::shared_ptr<Expression>> &arguments) :
    Statement (),
    name(name),
    arguments(arguments)
{
}

FunctionStatement::FunctionStatement()
{
}

void FunctionStatement::exec()
{
    QVector<std::shared_ptr<Value>> values;
    for (auto &argument : arguments) {
        values.append(argument->eval());
    }
    std::shared_ptr<Function> func = FunctionContainer::get(name);

    if (auto f = std::dynamic_pointer_cast<UserFunction>(func)) {
        for (int i = 0; i < arguments.size(); i++) {
            VariableContainer::set(f->getArgNames()[i], arguments[i]->eval());
        }
    }

    func->exec(values);
}

QString FunctionStatement::getName() const
{
    return name;
}

void FunctionStatement::setName(const QString &value)
{
    name = value;
}

QVector<std::shared_ptr<Expression> > FunctionStatement::getArguments() const
{
    return arguments;
}

void FunctionStatement::setArguments(const QVector<std::shared_ptr<Expression> > &value)
{
    arguments = value;
}
