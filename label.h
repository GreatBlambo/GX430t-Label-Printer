#ifndef LABEL_H
#define LABEL_H

#include <QString>
#include <vector>

struct Field
{
    QString name;
    QString value;
};

struct Column
{
    std::vector<Field> fields;
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
    std::vector<Column> *getColumns();

private:

    Header header;
    std::vector<Column> columns;

    static const int LINE_HEIGHT = 75;
    static const int COLUMN_WIDTH = 450;
    static const int PADDING = 30;
};

#endif // LABEL_H
