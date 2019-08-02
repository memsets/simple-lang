#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QString>
#include <QDebug>
#include <memory>

#include "token.h"
#include "ast/expression.h"
#include "ast/binaryexpression.h"
#include "ast/valueexpression.h"
#include "ast/unaryexpression.h"
#include "lib/variablecontainer.h"
#include "ast/variableexpression.h"
#include "ast/statement.h"
#include "ast/assignmentstatement.h"
#include "ast/blockstatement.h"
#include "lib/stringvalue.h"
#include "lib/booleanvalue.h"
#include "ast/functionexpression.h"
#include "ast/functionstatement.h"
#include "ast/arrayexpression.h"
#include "ast/arraystatement.h"

class Parser
{
    QVector<Token> tokens;
    int pos, size;
public:
    Parser(QVector<Token> tokens);
    Parser();
    QVector<std::shared_ptr<Statement>> statement();
    std::shared_ptr<Statement> blockStatement();
    std::shared_ptr<Statement> functionStatement();
    std::shared_ptr<Statement> arrayStatement();
    std::shared_ptr<Statement> assignmentStatement();
    std::shared_ptr<Expression> expression();
    std::shared_ptr<Expression> logical();
    std::shared_ptr<Expression> conditional();
    std::shared_ptr<Expression> additive();
    std::shared_ptr<Expression> multiplicative();
    std::shared_ptr<Expression> unary();
    std::shared_ptr<Expression> primary();
    Token peek(const int relativePosition) const;
    bool match(TokenType type);
};

#endif // PARSER_H
