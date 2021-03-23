#include "breakstatement.h"

BreakStatement::BreakStatement()
{   
}

void BreakStatement::exec()
{
    throw std::make_shared<BreakStatement>(*this);
}
