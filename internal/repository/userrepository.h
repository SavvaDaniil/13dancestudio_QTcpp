#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <internal/entity/user.h>
#include <QList>

#include "internal/data/applicationdbcontext.h"
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>

class UserRepository
{
public:
    UserRepository();

    User *findById(qint64 id);
    User *findByUsername(QString username);
    QList<User> *listAll();
};

#endif // USERREPOSITORY_H
