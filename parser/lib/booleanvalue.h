#ifndef BOOLEANVALUE_H
#define BOOLEANVALUE_H

#include <QString>

#include "value.h"

class BooleanValue : public Value
{
    uint32_t offset4b;
    bool value;
    uint8_t offset1b;
    uint16_t offset2b;
public:
    BooleanValue(bool value);
    BooleanValue();
    double asDouble() override;
    QString asString() override;
    bool asBoolean() override;
};

#endif // BOOLEANVALUE_H
