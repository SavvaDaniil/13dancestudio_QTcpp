#ifndef STYLEFACTORY_H
#define STYLEFACTORY_H

#include "qsqlquery.h"
#include <internal/entity/style.h>
#include <internal/viewmodel/Style/stylemicroviewmodel.h>


class StyleFactory
{
public:
    StyleFactory();
    Style *createFromQuery(QSqlQuery query);
    StyleMicroViewModel *toMicroViewModel(Style style);
};

#endif // STYLEFACTORY_H
