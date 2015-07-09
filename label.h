#ifndef LABEL_H
#define LABEL_H

#include <QString>
#include <QVector>

struct Field
{
    QString name;
    QString value;
};

struct Column
{
    QVector<Field> fields;
    void addField (Field& inField)
    {
        fields.push_back(inField);
    }
};

struct Header
{
    QString fontsize;
    QString content;
};

class Label
{
public:
    Label();
    void addColumn(Column& inColumn);
    void fillHeader(QString inFontSize, QString inContent);

    QString toString(); //returns the label formatted in zpl commands
    Header getHeader();
    QVector<Column>* getColumns();

private:

    Header header;
    QVector<Column> columns;

    const int stickerWidth = 0; //max width of the label
    const int stickerHeight = 0; //max height of the label
    static const int LINE_HEIGHT = 50;
    static const int COLUMN_WIDTH = 450;
    static const int PADDING = 20;
};

#endif // LABEL_H
