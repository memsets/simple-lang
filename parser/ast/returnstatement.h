#ifndef RETURNSTATEMENT_H
#define RETURNSTATEMENT_H

#include <QString>
#include <QVector>
#include <memory>

#include "statement.h"
#include "expression.h"

class ReturnStatement : public Statement
{
    std::shared_ptr<Expression> expression;
public:
    ReturnStatement(std::shared_ptr<Expression> expression);
    void exec() override;
    std::shared_ptr<Expression> getExpression() const;
    void setExpression(const std::shared_ptr<Expression> &value);
};

#endif // RETURNSTATEMENT_H
