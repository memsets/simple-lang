#ifndef FORSTATEMENT_H
#define FORSTATEMENT_H

#include <QDebug>
#include <QString>
#include <memory>

#include "expression.h"
#include "statement.h"
#include "../lib/variablecontainer.h"
#include "breakstatement.h"
#include "continuestatement.h"

class ForStatement : public Statement
{
    std::shared_ptr<Statement> initialization;
    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> increment;
    std::shared_ptr<Statement> forStatement;
public:
    ForStatement(std::shared_ptr<Statement> initialization,
            std::shared_ptr<Expression> condition,
            std::shared_ptr<Statement> increment,
            std::shared_ptr<Statement> forStatement);
    void exec() override;
};

#endif // FORSTATEMENT_H
