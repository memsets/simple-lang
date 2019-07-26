#ifndef DOUBLEVALUE_H
#define DOUBLEVALUE_H

#include <QString>

#include "value.h"

class DoubleValue : public Value
{
    double value;
public:
    DoubleValue(double value);
    double asDouble() override;
    QString asString() override;
    bool asBoolean() override;
};

#endif // DOUBLEVALUE_H
