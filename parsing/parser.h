#ifndef PARSER_H
#define PARSER_H

#include <QVector>
#include <QString>
#include <QDebug>
#include <memory>

#include "token.h"
#include "../entities/ast/expression.h"
#include "../entities/ast/binaryexpression.h"
#include "../entities/ast/valueexpression.h"
#include "../entities/ast/unaryexpression.h"
#include "../entities/variablecontainer.h"
#include "../entities/ast/variableexpression.h"
#include "../entities/ast/statement.h"
#include "../entities/ast/assignmentstatement.h"
#include "../entities/ast/blockstatement.h"
#include "../entities/stringvalue.h"
#include "../entities/booleanvalue.h"
#include "../entities/ast/functionexpression.h"
#include "../entities/ast/functionstatement.h"
#include "../entities/ast/arrayexpression.h"
#include "../entities/ast/arraystatement.h"
#include "../entities/ast/functiondefinestatement.h"
#include "../entities/ast/returnstatement.h"
#include "../entities/ast/ifstatement.h"
#include "../entities/ast/whilestatement.h"
#include "../entities/ast/forstatement.h"
#include "../entities/ast/continuestatement.h"
#include "../entities/ast/breakstatement.h"
#include "../entities/ast/importstatement.h"


class Parser
{
    QVector<Token> tokens;
    int pos, size;
public:
    Parser(const QVector<Token> &tokens);
    Parser();
    QVector<std::shared_ptr<Statement>> statement();
    std::shared_ptr<Statement> blockStatement();
    std::shared_ptr<Statement> importStatement();
    std::shared_ptr<Statement> functionDefineStatement();
    std::shared_ptr<Statement> returnStatement();
    std::shared_ptr<Statement> functionStatement();
    std::shared_ptr<Statement> arrayStatement();
    std::shared_ptr<Statement> continueStatement();
    std::shared_ptr<Statement> breakStatement();
    std::shared_ptr<Statement> forStatement();
    std::shared_ptr<Statement> whileStatement();
    std::shared_ptr<Statement> ifStatement();
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
    bool lookMatch(TokenType type, const int relativePosition = 0);
    void consume(TokenType type);
};

#endif // PARSER_H
