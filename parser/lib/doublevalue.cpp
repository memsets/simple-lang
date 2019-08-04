#include "doublevalue.h"

DoubleValue::DoubleValue(double value) : Value(), value(value)
{

}

double DoubleValue::asDouble()
{
    return value;
}

QString DoubleValue::asString()
{
    return QString::number(value);
}

bool DoubleValue::asBoolean()
{
    if (value == 0.0)
        return false;
    return true;
}
