#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <qstring.h>


class Tutorial
{
public:
    Tutorial();
    int id;
    QString name;
    int days;
    int price;
    int status;
    int orderInList;
    int styleId;
    int teacherId;
};

#endif // TUTORIAL_H
