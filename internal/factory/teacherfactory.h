#ifndef TEACHERFACTORY_H
#define TEACHERFACTORY_H

#include <qsqlquery.h>
#include <internal/entity/teacher.h>
#include <internal/viewmodel/Teacher/teachermicroviewmodel.h>

class TeacherFactory
{
public:
    TeacherFactory();
    Teacher *createFromQuery(QSqlQuery query);
    TeacherMicroViewModel *toMicroViewModel(Teacher teacher);
};

#endif // TEACHERFACTORY_H
