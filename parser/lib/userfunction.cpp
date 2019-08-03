#include "userfunction.h"

UserFunction::UserFunction(QVector<QString> argNames, std::shared_ptr<Statement> body) : Function(),
    argNames(argNames),
    body(body)
{
}

std::shared_ptr<Value> UserFunction::exec(QVector<std::shared_ptr<Value> > values)
{
    try {
        body->exec();
    } catch (std::shared_ptr<ReturnStatement> ret) {
        return ret->getExpression()->eval();
    }
    return std::make_shared<DoubleValue>(0.0);
}

QVector<QString> UserFunction::getArgNames() const
{
    return argNames;
}

void UserFunction::setArgNames(const QVector<QString> &value)
{
    argNames = value;
}
