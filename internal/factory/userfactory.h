#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "internal/entity/user.h"
#include "qdatetime.h"

#include <QSqlQuery>
class UserFactory
{
public:
    UserFactory();
    User *createFromQuery(
        QSqlQuery query
    );
};



#endif // USERFACTORY_H
