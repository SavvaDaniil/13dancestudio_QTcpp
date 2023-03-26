#ifndef TEACHERMICROVIEWMODEL_H
#define TEACHERMICROVIEWMODEL_H

#include <qjsonobject.h>
#include <qstring.h>


class TeacherMicroViewModel : public QJsonObject
{
public:
    TeacherMicroViewModel(int id, QString name);
    int id;
    QString name;

};

#endif // TEACHERMICROVIEWMODEL_H
