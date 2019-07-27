#include "parser.h"

Parser::Parser(QVector<Token> tokens) : tokens(tokens)
{
    this->pos = 0;
    this->size = tokens.size();
}

Parser::Parser()
{
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
    return printStatement();

}

std::shared_ptr<Statement> Parser::printStatement()
{
    if (match(TokenType::PRINT)) {
        return std::make_shared<PrintStatement>(PrintStatement(expression()));
    }
    return assignmentStatement();
}

std::shared_ptr<Statement> Parser::assignmentStatement()
{
    // TODO: Needs refactoring this condition
    if (peek(0).getType() == TokenType::WORD && peek(1).getType() == TokenType::EQ) {
        QString name = peek(0).getText();
        match(TokenType::WORD);
        match(TokenType::EQ);
        return std::make_shared<AssignmentStatement>(AssignmentStatement(name, expression()));
    }
    qFatal("Unknown statement");
}

std::shared_ptr<Expression> Parser::expression()
{
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
    }
    return primary();
}

std::shared_ptr<Expression> Parser::primary()
{
    Token current = peek(0);
    if (match(TokenType::NUM)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<DoubleValue>(current.getText().toDouble())));
    } else if (peek(0).getType() == TokenType::WORD && peek(1).getType() == TokenType::LPAREN) {
        match(TokenType::WORD);
        match(TokenType::LPAREN);
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
        match(TokenType::RPAREN);
        return expr;
    } else if (match(TokenType::WORD)) {
        return std::make_shared<VariableExpression>(VariableExpression(current.getText()));
    } else if (match(TokenType::TRUE)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<BooleanValue>(true)));
    } else if (match(TokenType::FALSE)) {
        return std::make_shared<ValueExpression>(
                    ValueExpression(std::make_shared<BooleanValue>(false)));
    } else {
        qFatal("Unknown token");
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

QVector<Token> Parser::getTokens() const
{
    return tokens;
}

void Parser::setTokens(const QVector<Token> &value)
{
    tokens = value;
}

int Parser::getPos() const
{
    return pos;
}

void Parser::setPos(int value)
{
    pos = value;
}

int Parser::getSize() const
{
    return size;
}

void Parser::setSize(int value)
{
    size = value;
}
