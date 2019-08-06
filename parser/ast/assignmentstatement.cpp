#include "assignmentstatement.h"

AssignmentStatement::AssignmentStatement(const QString &name, std::shared_ptr<Expression> expr) :
    Statement(),
    name(name),
    expr(expr)
{
}

AssignmentStatement::AssignmentStatement()
{
}

void AssignmentStatement::exec()
{
//    if (VariableContainer::isExists(name)) {
//        qFatal("This variable already exists");
//    }
    VariableContainer::set(name, expr->eval());
}

QString AssignmentStatement::getName() const
{
    return name;
}

void AssignmentStatement::setName(const QString &value)
{
    name = value;
}

std::shared_ptr<Expression> AssignmentStatement::getExpr() const
{
    return expr;
}

void AssignmentStatement::setExpr(const std::shared_ptr<Expression> &value)
{
    expr = value;
}

AssignmentStatement::~AssignmentStatement()
{
}
