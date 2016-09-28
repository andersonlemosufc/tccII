#ifndef STREAMPARSER_H
#define STREAMPARSER_H

#include <QString>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>

class StreamParser
{

public:
    const static QString types[];
    StreamParser();
    void getContent(QString filename);

private:
    QXmlStreamReader xml;
};

#endif // STREAMPARSER_H
