#ifndef TEACHERREPOSITORY_H
#define TEACHERREPOSITORY_H

#include <internal/entity/teacher.h>



class TeacherRepository
{
public:
    TeacherRepository();
    Teacher *findById(qint64 id);
    QList<Teacher> *listAll();
};

#endif // TEACHERREPOSITORY_H
