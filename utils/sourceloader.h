#ifndef SOURCELOADER_H
#define SOURCELOADER_H

#include <QString>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <iostream>

class SourceLoader
{
    QString path;
    QString source;
    static QString root;
public:
    SourceLoader();
    SourceLoader(QString path);
    QString loadFromFile();
    QString loadFromFile(QString path);
    static QString getRoot();
    static void setRoot(const QString value);
};

#endif // SOURCELOADER_H
