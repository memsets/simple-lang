#include "functiondefinestatement.h"

FunctionDefineStatement::FunctionDefineStatement(QString name, QVector<QString> argNames,
                                                 std::shared_ptr<Statement> body) : Statement(),
    name(name),
    argNames(argNames),
    body(body)
{
}

void FunctionDefineStatement::exec()
{
    FunctionContainer::set(name, std::make_shared<UserFunction>(UserFunction(argNames, body)));
}
