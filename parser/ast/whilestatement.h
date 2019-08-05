#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include <QDebug>
#include <QString>
#include <memory>

#include "expression.h"
#include "statement.h"
#include "../lib/variablecontainer.h"
#include "continuestatement.h"
#include "breakstatement.h"

class WhileStatement : public Statement
{
    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> whileStatement;
public:
    WhileStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> whileStatement);
    void exec() override;
};

#endif // WHILESTATEMENT_H
