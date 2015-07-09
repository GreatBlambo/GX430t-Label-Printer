#include "templateparser.h"

LabelParser::LabelParser(QFile& file, Label& inLabel) : Parser::Parser(file)
{
    //set the label object
    setLabel(inLabel);

    //assign callbacks to each tag
    tagCallbackMap["label"] = processLabel;
    tagCallbackMap["header"] = processHeader;
    tagCallbackMap["column"] = processColumn;
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
    Header tempHeader;
    qDebug("found header");
    while(xml.readNextStartElement())
    {
        //qDebug(xml.name().toLatin1());
        QString name(xml.name().toString());
        if (name == "size")
        {
            tempHeader.fontsize = xml.readElementText();
        } if (name == "content")
        {
            tempHeader.content = xml.readElementText();
        }
        //don't use skipCurrentElement in loop because we are currently within another element. the method will
        //skip that element because we haven't reached the end of that one yet (name() actually parses
        //the end of the element referenced, so it doesn't qualify to be skipped)
        //also readNextStartElement() moves ahead anyway. So only call it if you don't call readNextStartElement()
    }
    label->fillHeader(tempHeader.fontsize, tempHeader.content);
    //qDebug(xml.name().toLatin1());
}

void LabelParser::processColumn()
{
    qDebug("found column");

    Column tempColumn;
    while(xml.readNextStartElement())
    {
        //qDebug(xml.name().toLatin1());
        QString name(xml.name().toString());
        if (name == "field")
        {
            Field tempField = processField();
            tempColumn.addField(tempField);
        }
    }
    label->addColumn(tempColumn);
}

Field LabelParser::processField()
{

    qDebug("found field");
    Field tempField;

    while(xml.readNextStartElement())
    {
        QString name(xml.name().toString());
        if (name == "name")
        {
            tempField.name = xml.readElementText();
        }
        if (name == "value")
        {
            tempField.value = xml.readElementText();
        }
    }
    return tempField;
}

void LabelParser::setLabel(Label& inLabel)
{
    label = &inLabel;
}
