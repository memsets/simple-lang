#ifndef BREAKSTATEMENT_H
#define BREAKSTATEMENT_H

#include <QDebug>
#include <QString>
#include <memory>

#include "expression.h"
#include "statement.h"

class BreakStatement : public Statement
{
public:
    BreakStatement();
    void exec() override;
};

#endif // BREAKSTATEMENT_H
