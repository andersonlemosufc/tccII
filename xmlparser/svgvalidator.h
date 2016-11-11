#ifndef SVGVALIDATOR_H
#define SVGVALIDATOR_H
//#define LIBXML_VALID_ENABLED
#include <QXmlSchema>
#include <QDebug>
#include <QFile>
class SVGValidator
{
public:
    SVGValidator();
    static bool isValidSVG(QString filename);
};

#endif // SVGVALIDATOR_H
