#include "continuestatement.h"

ContinueStatement::ContinueStatement()
{
}

void ContinueStatement::exec()
{
    throw std::make_shared<ContinueStatement>(*this);
}
