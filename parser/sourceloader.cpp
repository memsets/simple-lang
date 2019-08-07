#include "sourceloader.h"

QString SourceLoader::root = "";

SourceLoader::SourceLoader()
{
    this->path = "";
}

SourceLoader::SourceLoader(QString path)
{
    this->path = path;
}

QString SourceLoader::loadFromFile()
{
    QString fullpath = root + path;
    if (path.isEmpty()) {
        throw std::runtime_error("File path is empty");
    }

    QFile file(fullpath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error("Could not open the file");

    QTextStream in(&file);
    source = in.readAll();
    return source;
}

QString SourceLoader::loadFromFile(QString path)
{
    this->path = path;
    return loadFromFile();
}

QString SourceLoader::getRoot()
{
    return root;
}

void SourceLoader::setRoot(const QString value)
{
    root = value;
}
