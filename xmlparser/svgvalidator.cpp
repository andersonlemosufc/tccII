#include "svgvalidator.h"

SVGValidator::SVGValidator()
{

}

bool SVGValidator::isValidSVG(QString filename)
{
    QUrl url("https://www.w3.org/TR/2002/WD-SVG11-20020108/SVG.xsd");

    QXmlSchema schema;
    if(schema.load(url)){
        qDebug() << "sim";
    } else {
        qDebug() << "nao";
    }
    return false;
}

