#include "booleanvalue.h"

BooleanValue::BooleanValue(bool value) : Value(),
    value(value)
{
}

BooleanValue::BooleanValue()
{
}

double BooleanValue::asDouble()
{
    if (value == true)
        return 1.0;
    return 0.0;
}

QString BooleanValue::asString()
{
    if (value == true)
        return QString("true");
    return QString("false");
}

bool BooleanValue::asBoolean()
{
    return value;
}
