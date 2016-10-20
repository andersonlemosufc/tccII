#ifndef SVGVALIDATOR_H
#define SVGVALIDATOR_H

#include <QXmlSchema>
#include <QDebug>

class SVGValidator
{
public:
    SVGValidator();
    static bool isValidSVG(QString filename);
};

#endif // SVGVALIDATOR_H
