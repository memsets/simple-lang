#ifndef CONTINUESTATEMENT_H
#define CONTINUESTATEMENT_H

#include <QDebug>
#include <QString>
#include <memory>

#include "expression.h"
#include "statement.h"

class ContinueStatement : public Statement
{
public:
    ContinueStatement();
    void exec() override;
};

#endif // CONTINUESTATEMENT_H
