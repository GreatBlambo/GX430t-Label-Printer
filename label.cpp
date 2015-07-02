#include "label.h"

Label::Label()
{

}
void Label::addColumn(Column& inColumn)
{
    columns.push_back(inColumn);
}

void Label::fillHeader(QString inFont, QString inFontSize, QString inContent)
{
    header.font = inFont;
    header.fontsize = inFontSize;
    header.content = inContent;
}
