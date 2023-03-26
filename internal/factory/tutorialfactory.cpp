#include "tutorialfactory.h"

TutorialFactory::TutorialFactory()
{

}

Tutorial *TutorialFactory::createFromQuery(QSqlQuery query)
{
    Tutorial *tutorial = new Tutorial();
    tutorial->id = query.value(0).toInt();

    tutorial->name = query.value(1).toString();

    tutorial->days = query.value(2).toInt();
    tutorial->price = query.value(3).toInt();
    tutorial->status = query.value(4).toInt();
    tutorial->orderInList = query.value(5).toInt();
    tutorial->styleId = query.value(6).toInt();
    tutorial->teacherId = query.value(7).toInt();

    return tutorial;
}
