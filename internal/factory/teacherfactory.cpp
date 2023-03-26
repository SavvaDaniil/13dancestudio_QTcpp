#include "teacherfactory.h"

TeacherFactory::TeacherFactory()
{

}

Teacher *TeacherFactory::createFromQuery(QSqlQuery query)
{
    Teacher *teacher = new Teacher();
    teacher->id = query.value(0).toInt();
    teacher->name = query.value(1).toString();
    teacher->orderInList = query.value(2).toInt();
    teacher->status = query.value(3).toInt();

    return teacher;
}

TeacherMicroViewModel *TeacherFactory::toMicroViewModel(Teacher teacher)
{
    TeacherMicroViewModel *teacherMicroViewModel = new TeacherMicroViewModel(teacher.id, teacher.name);
    return teacherMicroViewModel;
}
