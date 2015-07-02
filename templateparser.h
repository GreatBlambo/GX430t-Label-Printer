#ifndef TEMPLATEPARSER_H
#define TEMPLATEPARSER_H

#include <QFile>
#include <QXmlStreamReader>
#include <QString>
#include <QDebug>
#include <map>

#include "label.h"

template <class ReaderObject>
class Parser
{
public:
    Parser(QFile& xmlFile)
    {
        _filename = xmlFile.fileName();
        if (!xmlFile.exists())
        {
            qDebug("File does not exist");
            return;
        }
        if(!xmlFile.open(QIODevice::ReadOnly))
        {
            qDebug("Could not open file!");
            return;
        }
        xml.setDevice(&xmlFile);
    }
    void read()
    {
        static_cast<ReaderObject*>(this)->start();
    }

protected:
    void findChildrenAndOperate()
    {
        while(xml.readNextStartElement())
        {
            void (ReaderObject::*pCallback)() = (tagCallbackMap[xml.name().toString()]);
            if (pCallback != NULL && xml.isStartElement())
            {
                ((ReaderObject*)this->*(pCallback))();
            }
            xml.skipCurrentElement();
        }
    } //runs while loop that reads tags from stream and runs a callback


    QString _filename;
    QXmlStreamReader xml;

    std::map<QString, void (ReaderObject::*)()> tagCallbackMap;
};

class LabelParser : Parser<LabelParser>
{
public:
    LabelParser(QFile& xmlFile, Label& inLabel);
    void start();
private:
    Label* label;

    void processLabel();
    void processHeader();
    void processColumn();
    void processField();
    void processValue();

    void setLabel(Label& inLabel);
};

#endif // TEMPLATEPARSER_H
