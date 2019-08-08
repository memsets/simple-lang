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
    ForStatement();
    void exec() override;
    std::shared_ptr<Statement> getInitialization() const;
    void setInitialization(const std::shared_ptr<Statement> &value);
    std::shared_ptr<Expression> getCondition() const;
    void setCondition(const std::shared_ptr<Expression> &value);
    std::shared_ptr<Statement> getIncrement() const;
    void setIncrement(const std::shared_ptr<Statement> &value);
    std::shared_ptr<Statement> getForStatement() const;
    void setForStatement(const std::shared_ptr<Statement> &value);
};

#endif // FORSTATEMENT_H
