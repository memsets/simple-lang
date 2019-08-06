#include "functionexpression.h"

FunctionExpression::FunctionExpression(const QString &name,
                                       const QVector<std::shared_ptr<Expression>> &arguments) :
    Expression (),
    name(name),
    arguments(arguments)
{
}

std::shared_ptr<Value> FunctionExpression::eval()
{
    QVector<std::shared_ptr<Value>> values;

    for (auto &expr : arguments) {
        values.append(expr->eval());
    }

    if (!FunctionContainer::isExists(name)) {
        throw std::runtime_error("Unknown function " + name.toLatin1());
    }

    std::shared_ptr<Function> receivedFunction = FunctionContainer::get(name);

    if (auto function = std::dynamic_pointer_cast<UserFunction>(receivedFunction)) {
        for (int i = 0; i < arguments.size(); i++) {
            VariableContainer::set(function->getArgNames()[i], arguments[i]->eval());
        }
    }

    return FunctionContainer::get(name)->exec(values);
}

QString FunctionExpression::getName() const
{
    return name;
}

void FunctionExpression::setName(const QString &value)
{
    name = value;
}

QVector<std::shared_ptr<Expression> > FunctionExpression::getArguments() const
{
    return arguments;
}

void FunctionExpression::setArguments(const QVector<std::shared_ptr<Expression> > &value)
{
    arguments = value;
}
