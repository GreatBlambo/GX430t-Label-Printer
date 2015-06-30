#ifndef TEMPLATEPARSER_H
#define TEMPLATEPARSER_H

#include <QXmlStreamReader>
#include <QString>

template <class ReaderObject>
class Parser
{
public:
    void read();
protected:
    void findAndOperate(ReaderObject* pDerivedParser, void (ReaderObject::*pAction)(), const char * name)
    {

    };

    QString _filename;
    QXmlStreamReader xml;
};

class LabelParser : Parser<LabelParser>
{
public:
    LabelParser(const QString filename);
private:
    void processLabel();
    void processHeader();
    void processField();
};

#endif // TEMPLATEPARSER_H
