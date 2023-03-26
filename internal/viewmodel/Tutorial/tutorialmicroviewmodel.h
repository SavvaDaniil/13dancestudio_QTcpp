#ifndef TUTORIALMICROVIEWMODEL_H
#define TUTORIALMICROVIEWMODEL_H

#include <qstring.h>
#include <internal/viewmodel/Teacher/teachermicroviewmodel.h>
#include <internal/viewmodel/Style/stylemicroviewmodel.h>


class TutorialMicroViewModel
{
public:
    TutorialMicroViewModel(int id, QString *name, QString *poster_src, TeacherMicroViewModel *teacherMicroViewModel, StyleMicroViewModel *styleMicroViewModel, int price, bool is_active, int order_in_list);
    int id;
    QString *name;
    QString *poster_src;
    TeacherMicroViewModel *teacherMicroViewModel;
    StyleMicroViewModel *styleMicroViewModel;
    int price;
    bool is_active;
    int order_in_list;
};

#endif // TUTORIALMICROVIEWMODEL_H
