#include "stringvalue.h"

StringValue::StringValue(QString value) : Value(),
    value(value)
{   
}

StringValue::StringValue()
{
}

double StringValue::asDouble()
{
    return value.toDouble();
}

QString StringValue::asString()
{
    return value;
}

bool StringValue::asBoolean()
{
    if (value == "")
        return false;
    return true;
}

StringValue::~StringValue()
{
}
