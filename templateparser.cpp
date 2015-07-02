#include "templateparser.h"

LabelParser::LabelParser(QFile& file, Label& inLabel) : Parser::Parser(file)
{
    //set the label object
    setLabel(inLabel);

    //assign callbacks to each tag
    tagCallbackMap["label"] = processLabel;
    tagCallbackMap["header"] = processHeader;
    tagCallbackMap["column"] = processColumn;
    tagCallbackMap["field"] = processField;
}

void LabelParser::start()
{
    findChildrenAndOperate();
}

void LabelParser::processLabel()
{
    qDebug("found label");
    findChildrenAndOperate();
}

void LabelParser::processHeader()
{

    qDebug("found header");
    while(xml.readNextStartElement())
    {
        QString name(xml.name().toString());
        qDebug(name.toLatin1());
        xml.skipCurrentElement();
    }
}

void LabelParser::processColumn()
{
    qDebug("found column");
}

void LabelParser::processField()
{
    qDebug("found field");
}

void LabelParser::setLabel(Label& inLabel)
{
    label = &inLabel;
}
