#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QString>
#include <QDebug>
#include <memory>

#include "token.h"
#include "ast/expression.h"
#include "ast/binaryexpression.h"
#include "ast/numberexpression.h"
#include "ast/unaryexpression.h"
#include "lib/variablecontainer.h"

class Parser
{
    QVector<Token> tokens;
    int pos, size;

public:
    Parser(QVector<Token> tokens);
    std::shared_ptr<Expression> expression();
    std::shared_ptr<Expression> additive();
    std::shared_ptr<Expression> multiplicative();
    std::shared_ptr<Expression> unary();
    std::shared_ptr<Expression> primary();
    Token peek(const int relativePosition) const;
    bool match(TokenType type);
};

#endif // PARSER_H
