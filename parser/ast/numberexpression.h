#ifndef NUMBEREXPRESSION_H
#define NUMBEREXPRESSION_H

#include <QChar>
#include <memory>

#include "expression.h"

class NumberExpression : public Expression
{
    double number;
public:
    NumberExpression(const double number);
    NumberExpression();
    double eval() override;
    double getNumber() const;
    void setNumber(double value);
};

#endif // NUMBEREXPRESSION_H
