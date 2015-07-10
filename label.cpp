#include "label.h"

Label::Label()
{

}
void Label::addColumn(Column& inColumn)
{
    columns.push_back(inColumn);
}

void Label::fillHeader(QString inFontSize, QString inContent)
{
    header.fontsize = inFontSize;
    header.content = inContent;
}

QString Label::toString()
{
    std::string padding_s = std::to_string(PADDING);
    QString padding_qs(padding_s.c_str());
    QString zbl("");
    QString pre("^XA^FO");
    QString lineborder("___________________");
    QString preLine("^FS^FO");
    QString post("^A0,");
    post.append(header.fontsize);
    post.append("^FD");
    QString fieldpost("^AS,40^FD");

    QString headerSpacing = header.fontsize;
    int headerSpacing_int = headerSpacing.toInt() + 10;

    //format header
    if (!header.content.isEmpty())
    {
        zbl.append(pre);
        zbl.append(padding_qs);
        zbl.append(",");
        zbl.append(padding_qs);
        zbl.append(post);
        zbl.append(header.content);
        zbl.append(preLine);
        zbl.append(padding_qs);
        zbl.append(",");
        zbl.append(padding_qs);
        zbl.append(post);
        zbl.append(lineborder);
    }

    QString end("^XZ");
    //format columns
    for (int i = 0; i < columns.size(); i++)
    {

        Field field;

        int x,y;
        Column column = columns.at(i);

        x = (i * COLUMN_WIDTH) + PADDING;
        std::string xStr = std::to_string(x);
        for (int j = 0; j < column.fields.size(); j++)
        {
            QString fieldstring("");

            y = (j * LINE_HEIGHT) + headerSpacing_int + PADDING;
            field = column.fields.at(j);

            fieldstring.append(field.name);
            fieldstring.append(": ");
            fieldstring.append(field.value);

            std::string yStr = std::to_string(y);

            QString genPre("");
            genPre.append(preLine);
            genPre.append(xStr.c_str());
            genPre.append(",");
            genPre.append(yStr.c_str());

            zbl.append(genPre);
            zbl.append(fieldpost);
            zbl.append(fieldstring);
        }
    }
    zbl.append(end);


    return zbl;
}

Header Label::getHeader()
{
    return header;
}
