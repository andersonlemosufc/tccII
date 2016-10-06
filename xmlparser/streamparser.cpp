#include "streamparser.h"

const QString  StreamParser::types[] =  {
    "NoToken",
    "Invalid",
    "StartDocument",
    "EndDocument",
    "StartElement",
    "EndElement",
    "Characters",
    "Comment",
    "DTD",
    "EntityReference",
    "ProcessingInstruction"
};

StreamParser::StreamParser()
{

}

void StreamParser::getContent(QString filename)
{
    QFile xmlFile(filename);
    xmlFile.open(QIODevice::ReadOnly);
    this->xml.setDevice(&xmlFile);

    QFile file(filename+".aux");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    QTextStream out(&file);

    while(xml.tokenType()!=QXmlStreamReader::EndDocument){
        switch (xml.tokenType()) {
            case QXmlStreamReader::StartElement:
                foreach (QXmlStreamAttribute atr, xml.attributes()){
                    out << atr.value().toString().trimmed();
                }
                break;
            case QXmlStreamReader::Characters:
                out << xml.text().toString().trimmed();
                break;
            default: break;
        }
        xml.readNext();
    }
}

