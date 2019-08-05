#ifndef IFSTATEMENT_H
#define IFSTATEMENT_H

#include <QDebug>
#include <QString>
#include <memory>

#include "expression.h"
#include "statement.h"

class IfStatement : public Statement
{
    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> ifStatement;
    std::shared_ptr<Statement> elseStatement;
public:
    IfStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> ifStatement,
                std::shared_ptr<Statement> elseStatement);
    void exec() override;
};

#endif // IFSTATEMENT_H
