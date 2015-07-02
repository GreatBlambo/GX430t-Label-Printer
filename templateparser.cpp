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
        Header tempHeader;
        QString name(xml.name().toString());
        if (name == "font")
        {
            tempHeader.font = xml.readElementText();
        } else if (name == "size")
        {
            tempHeader.fontsize = xml.readElementText();
        } if (name == "content")
        {
            tempHeader.content = xml.readElementText();
        }
        label->fillHeader(tempHeader.font, tempHeader.fontsize, tempHeader.content);
        qDebug(label->header.font.toLatin1());
        qDebug(label->header.fontsize.toLatin1());
        qDebug(label->header.content.toLatin1());
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
