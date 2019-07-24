#include "printstatement.h"

PrintStatement::PrintStatement(std::shared_ptr<Expression> expr) : Statement(), expr(expr)
{
}

PrintStatement::PrintStatement()
{
}

void PrintStatement::exec()
{
    qInfo() << expr->eval()->asString();
}

PrintStatement::~PrintStatement()
{
}
