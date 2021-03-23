#ifndef WHILESTATEMENT_H
#define WHILESTATEMENT_H

#include <QDebug>
#include <QString>
#include <memory>

#include "expression.h"
#include "statement.h"
#include "../../entities/variablecontainer.h"
#include "continuestatement.h"
#include "breakstatement.h"

class WhileStatement : public Statement
{
    std::shared_ptr<Expression> condition;
    std::shared_ptr<Statement> whileStatement;
public:
    WhileStatement(std::shared_ptr<Expression> condition, std::shared_ptr<Statement> whileStatement);
    void exec() override;
    WhileStatement();
    std::shared_ptr<Expression> getCondition() const;
    void setCondition(const std::shared_ptr<Expression> &value);
    std::shared_ptr<Statement> getWhileStatement() const;
    void setWhileStatement(const std::shared_ptr<Statement> &value);
};

#endif // WHILESTATEMENT_H
