#include "stylefactory.h"

StyleFactory::StyleFactory()
{

}

Style *StyleFactory::createFromQuery(QSqlQuery query)
{
    Style *style = new Style();
    style->id = query.value(0).toInt();
    style->name = query.value(1).toString();
    style->orderInList = query.value(2).toInt();
    style->status = query.value(3).toInt();

    return style;
}

StyleMicroViewModel *StyleFactory::toMicroViewModel(Style style)
{
    StyleMicroViewModel *styleMicroViewModel = new StyleMicroViewModel(style.id, style.name);
    return styleMicroViewModel;
}
