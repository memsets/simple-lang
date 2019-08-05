#include "parser.h"

Parser::Parser(QVector<Token> tokens) : tokens(tokens)
{
    this->pos = 0;
    this->size = tokens.size();
}

Parser::Parser()
{
    this->pos = 0;
    this->size = 0;
}

QVector<std::shared_ptr<Statement>> Parser::statement()
{
    QVector<std::shared_ptr<Statement>> statements;

    while (!match(TokenType::END)) {
        statements.append(blockStatement());
    }
    return statements;
}

std::shared_ptr<Statement> Parser::blockStatement()
{
    auto statements = QVector<std::shared_ptr<Statement>>();
    if (match(TokenType::LBRACE)) {
        while (!match(TokenType::RBRACE)) {
            statements.append(blockStatement());
        }
        return std::make_shared<BlockStatement>(BlockStatement(statements));
    }
    return functionDefineStatement();

}

std::shared_ptr<Statement> Parser::functionDefineStatement()
{
    if (match(TokenType::FUNCTION)) {
        QString name = peek(0).getText();

        consume(TokenType::WORD);
        consume(TokenType::LPAREN);

        QVector<QString> args;
        while (!match(TokenType::RPAREN)) {
            args.append(peek(0).getText());
            consume(TokenType::WORD);
            match(TokenType::COMMA);
        }
        return std::make_shared<FunctionDefineStatement>(
                    FunctionDefineStatement(name, args, blockStatement()));
    }
    return returnStatement();
}

std::shared_ptr<Statement> Parser::returnStatement()
{
    if (match(TokenType::RETURN)) {
        return std::make_shared<ReturnStatement>(ReturnStatement(expression()));
    }
    return functionStatement();
}

std::shared_ptr<Statement> Parser::functionStatement()
{
    if (lookMatch(TokenType::WORD) && lookMatch(TokenType::LPAREN, 1)) {
        QString name = peek(0).getText();

        consume(TokenType::WORD);
        consume(TokenType::LPAREN);

        QVector<std::shared_ptr<Expression>> args;
        while (!match(TokenType::RPAREN)) {
            args.append(expression());
            match(TokenType::COMMA);
        }

        return std::make_shared<FunctionStatement>(FunctionStatement(name, args));

    }
    return arrayStatement();
}

std::shared_ptr<Statement> Parser::arrayStatement()
{
    if (lookMatch(TokenType::WORD) && lookMatch(TokenType::LBRACKET, 1)) {
        QString name = peek(0).getText();
        consume(TokenType::WORD);

        QVector<std::shared_ptr<Expression>> indices;
        do {
            consume(TokenType::LBRACKET);
            indices.append(expression());
            consume(TokenType::RBRACKET);
        } while (peek(0).getType() == TokenType::LBRACKET);

        consume(TokenType::EQ);
        return std::make_shared<ArrayStatement>(name, indices, expression());
    }
    return continueStatement();
}

std::shared_ptr<Statement> Parser::continueStatement()
{
    if (match(TokenType::CONTINUE)) {
        return std::make_shared<ContinueStatement>(ContinueStatement());
    }
    return breakStatement();
}

std::shared_ptr<Statement> Parser::breakStatement()
{
    if (match(TokenType::BREAK)) {
        return std::make_shared<BreakStatement>(BreakStatement());
    }
    return forStatement();
}

std::shared_ptr<Statement> Parser::forStatement()
{
    if (lookMatch(TokenType::FOR) && lookMatch(TokenType::LPAREN, 1)) {
        consume(TokenType::FOR);
        consume(TokenType::LPAREN);

        std::shared_ptr<Statement> initialization = functionDefineStatement();
        consume(TokenType::SEMICOLON);

        std::shared_ptr<Expression> expr = expression();
        consume(TokenType::SEMICOLON);

        std::shared_ptr<Statement> increment = functionDefineStatement();
        consume(TokenType::RPAREN);

        return std::make_shared<ForStatement>(
                    ForStatement(initialization, expr, increment, blockStatement()));
    }
    return whileStatement();
}

std::shared_ptr<Statement> Parser::whileStatement()
{
    if (lookMatch(TokenType::WHILE) && lookMatch(TokenType::LPAREN, 1)) {
        consume(TokenType::WHILE);
        consume(TokenType::LPAREN);

        std::shared_ptr<Expression> expr = expression();
        consume(TokenType::RPAREN);

        std::shared_ptr<Statement> whileState = blockStatement();
        return std::make_shared<WhileStatement>(WhileStatement(expr, whileState));
    }
    return ifStatement();
}

std::shared_ptr<Statement> Parser::ifStatement()
{
    if (lookMatch(TokenType::IF) && lookMatch(TokenType::LPAREN, 1)) {
        consume(TokenType::IF);
        consume(TokenType::LPAREN);

        std::shared_ptr<Expression> expr = expression();
        consume(TokenType::RPAREN);

        std::shared_ptr<Statement> ifState = blockStatement();
        std::shared_ptr<Statement> elseState = nullptr;
        if (match(TokenType::ELSE)) {
            std::shared_ptr<Statement> elseState = blockStatement();
        }
        return std::make_shared<IfStatement>(IfStatement(expr, ifState, elseState));
    }
    return assignmentStatement();
}

std::shared_ptr<Statement> Parser::assignmentStatement()
{
    if (lookMatch(TokenType::WORD) && lookMatch(TokenType::EQ, 1)) {
        QString name = peek(0).getText();
        consume(TokenType::WORD);
        consume(TokenType::EQ);
        return std::make_shared<AssignmentStatement>(AssignmentStatement(name, expression()));
    }
    throw std::runtime_error("Unknown statement");
}

std::shared_ptr<Expression> Parser::expression()
{
    // head of all expressions.
    return logical();
}

std::shared_ptr<Expression> Parser::logical()
{
    auto expr = conditional();
    while (true) {
        if (match(TokenType::AND)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::AND, expr, conditional()));
            continue;
        } else if (match(TokenType::OR)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::OR, expr, conditional()));
            continue;
        }
        break;
    }
    return expr;
}

std::shared_ptr<Expression> Parser::conditional()
{
    auto expr = additive();
    while (true) {
        if (match(TokenType::LT)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::LT, expr, additive()));
            continue;
        } else if (match(TokenType::GT)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::GT, expr, additive()));
            continue;
        } else if (match(TokenType::EQEQ)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::EQEQ, expr, additive()));
            continue;
        } else if (match(TokenType::NOTEQ)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::NOTEQ, expr, additive()));
            continue;
        } else if (match(TokenType::LTEQ)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::LTEQ, expr, additive()));
            continue;
        } else if (match(TokenType::GTEQ)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::GTEQ, expr, additive()));
            continue;
        }
        break;
    }
    return expr;
}

std::shared_ptr<Expression> Parser::additive()
{
    auto expr = multiplicative();
    while (true) {
        if (match(TokenType::PLUS)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::PLUS, expr, multiplicative()));
            continue;
        } else if (match(TokenType::MINUS)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::MINUS, expr, multiplicative()));
            continue;
        }
        break;
    }
    return expr;
}

std::shared_ptr<Expression> Parser::multiplicative()
{
    auto expr = unary();
    while (true) {
        if (match(TokenType::STAR)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::STAR, expr, unary()));
            continue;
        } else if (match(TokenType::SLASH)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::SLASH, expr, unary()));
            continue;
        } else if (match(TokenType::PER)) {
            expr = std::make_shared<BinaryExpression>(
                        BinaryExpression(TokenType::PER, expr, unary()));
            continue;
        }
        break;
    }
    return expr;
}

std::shared_ptr<Expression> Parser::unary()
{
    if (match(TokenType::MINUS)) {
        return std::make_shared<UnaryExpression>(
                    UnaryExpression(TokenType::MINUS, primary()));
    } else if (match(TokenType::PLUS)) {
        return std::make_shared<UnaryExpression>(
                    UnaryExpression(TokenType::PLUS, primary()));
    } else if (match(TokenType::NOT)) {
        return std::make_shared<UnaryExpression>(
                    UnaryExpression(TokenType::NOT, primary()));
    }
    return primary();
}

std::shared_ptr<Expression> Parser::primary()
{
    Token current = peek(0);
    if (match(TokenType::NUM)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<DoubleValue>(current.getText().toDouble())));
    } else if (lookMatch(TokenType::WORD) && lookMatch(TokenType::LPAREN, 1)) {
        consume(TokenType::WORD);
        consume(TokenType::LPAREN);
        QVector<std::shared_ptr<Expression>> args;
        while (!match(TokenType::RPAREN)) {
            args.append(expression());
            match(TokenType::COMMA);
        }
        return std::make_shared<FunctionExpression>(current.getText(), args);
    } else if (match(TokenType::TEXT)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<StringValue>(current.getText())));
    } else if (match(TokenType::LPAREN)) {
        std::shared_ptr<Expression> expr = expression();
        consume(TokenType::RPAREN);
        return expr;
    } else if (lookMatch(TokenType::WORD) && lookMatch(TokenType::LBRACKET, 1)) {
        QString name = current.getText();
        consume(TokenType::WORD);

        QVector<std::shared_ptr<Expression>> indices;
        do {
            consume(TokenType::LBRACKET);
            indices.append(expression());
            consume(TokenType::RBRACKET);
        } while (lookMatch(TokenType::LBRACKET));
        return std::make_shared<ArrayExpression>(name, indices);
    } else if (match(TokenType::WORD)) {
        return std::make_shared<VariableExpression>(VariableExpression(current.getText()));
    } else if (match(TokenType::TRUE)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<BooleanValue>(true)));
    } else if (match(TokenType::FALSE)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<BooleanValue>(false)));
    } else {
        throw std::runtime_error("Unknown token");
    }
}

Token Parser::peek(const int relativePosition) const
{
    const int position = relativePosition + pos;
    if (position >= size) {
        return Token(TokenType::END, "");
    }
    return tokens[position];
}

bool Parser::match(TokenType type)
{
    const Token current = peek(0);
    if (current.getType() == type) {
        pos++;
        return true;
    }
    return false;
}

bool Parser::lookMatch(TokenType type, const int relativePosition)
{
    const Token current = peek(relativePosition);
    if (current.getType() == type) {
        return true;
    }
    return false;
}

void Parser::consume(TokenType type)
{
    const Token current = peek(0);
    if (current.getType() != type) {
        throw std::runtime_error("Other token expected");
    }
    pos++;
}
