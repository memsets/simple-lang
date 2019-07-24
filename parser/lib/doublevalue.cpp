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
