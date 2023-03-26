#ifndef TUTORIALFACTORY_H
#define TUTORIALFACTORY_H

#include <internal/entity/tutorial.h>
#include <qsqlquery.h>

class TutorialFactory
{
public:
    TutorialFactory();
    Tutorial *createFromQuery(QSqlQuery query);
};

#endif // TUTORIALFACTORY_H
