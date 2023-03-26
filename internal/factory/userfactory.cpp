#include "userfactory.h"

UserFactory::UserFactory()
{

}

User *UserFactory::createFromQuery(QSqlQuery query)
{

    //qDebug() << db.lastError();
    User *user = new User();
    user->id = query.value(0).toInt();
    user->username = query.value(1).toString();

    ...

    return user;
}

