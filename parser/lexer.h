#ifndef LEXER_H
#define LEXER_H

#include <QVector>
#include <QChar>
#include <QHash>
#include <QString>
#include <QDebug>

#include "token.h"

class Lexer
{
    static const QChar END;
    QHash<QString, TokenType> operators;
    QVector<Token> tokens;
    const QString source;
    int pos;
public:
    Lexer(QString source);
    QVector<Token> tokenize();
    void tokenizeNumber();
    void tokenizeOperator();
    void tokenizeWord();
    QChar peek(const int relativePosition) const;
    QChar next();
};

#endif // LEXER_H
