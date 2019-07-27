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
    static const QString OPERATOR_CHARS;
    static const QChar END;
    QHash<QString, TokenType> operators;
    QHash<QString, TokenType> keywords;
    QVector<Token> tokens;
    const QString source;
    int pos;
public:
    Lexer(QString source);
    QVector<Token> tokenize();
    void tokenizeNumber();
    void tokenizeOperator();
    void tokenizeWord();
    void tokenizeComment();
    void tokenizeMultilineComment();
    void tokenizeText();
    QChar peek(const int relativePosition) const;
    QChar next(int numOfPositions = 1);
};

#endif // LEXER_H
