#ifndef PRINTSTATEMENT_H
#define PRINTSTATEMENT_H

#include <memory>
#include <QDebug>

#include "statement.h"
#include "expression.h"

class PrintStatement : public Statement
{
    std::shared_ptr<Expression> expr;
public:
    PrintStatement(std::shared_ptr<Expression> expr);
    PrintStatement();
    void exec() override;
    ~PrintStatement() override;
};

#endif // PRINTSTATEMENT_H
