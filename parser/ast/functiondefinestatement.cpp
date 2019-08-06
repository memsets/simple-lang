#include "functiondefinestatement.h"

FunctionDefineStatement::FunctionDefineStatement(const QString &name, const QVector<QString> &argNames,
                                                 std::shared_ptr<Statement> body) :
    Statement(),
    name(name),
    argNames(argNames),
    body(body)
{
}

FunctionDefineStatement::FunctionDefineStatement()
{
}

void FunctionDefineStatement::exec()
{
    FunctionContainer::set(name, std::make_shared<UserFunction>(UserFunction(argNames, body)));
}

QString FunctionDefineStatement::getName() const
{
    return name;
}

void FunctionDefineStatement::setName(const QString &value)
{
    name = value;
}

QVector<QString> FunctionDefineStatement::getArgNames() const
{
    return argNames;
}

void FunctionDefineStatement::setArgNames(const QVector<QString> &value)
{
    argNames = value;
}

std::shared_ptr<Statement> FunctionDefineStatement::getBody() const
{
    return body;
}

void FunctionDefineStatement::setBody(const std::shared_ptr<Statement> &value)
{
    body = value;
}
