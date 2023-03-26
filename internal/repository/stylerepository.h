#ifndef STYLEREPOSITORY_H
#define STYLEREPOSITORY_H

#include <internal/entity/style.h>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>


class StyleRepository
{
public:
    StyleRepository();

    Style *findById(qint64 id);
    QList<Style> *listAll();
};

#endif // STYLEREPOSITORY_H
