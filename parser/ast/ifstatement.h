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
    IfStatement();
    void exec() override;
    std::shared_ptr<Expression> getCondition() const;
    void setCondition(const std::shared_ptr<Expression> &value);
    std::shared_ptr<Statement> getIfStatement() const;
    void setIfStatement(const std::shared_ptr<Statement> &value);
    std::shared_ptr<Statement> getElseStatement() const;
    void setElseStatement(const std::shared_ptr<Statement> &value);
};

#endif // IFSTATEMENT_H
