#ifndef ASSIGNMENTSTATEMENT_H
#define ASSIGNMENTSTATEMENT_H

#include <QDebug>
#include <QString>
#include <memory>

#include "expression.h"
#include "statement.h"
#include "../../entities/variablecontainer.h"

class AssignmentStatement : public Statement
{
    QString name;
    std::shared_ptr<Expression> expr;
public:
    AssignmentStatement(const QString &name, std::shared_ptr<Expression> expr);
    AssignmentStatement();
    void exec() override;
    ~AssignmentStatement() override;
    QString getName() const;
    void setName(const QString &value);
    std::shared_ptr<Expression> getExpr() const;
    void setExpr(const std::shared_ptr<Expression> &value);
};

#endif // ASSIGNMENTSTATEMENT_H
