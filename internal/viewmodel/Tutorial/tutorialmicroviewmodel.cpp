#include "tutorialmicroviewmodel.h"

TutorialMicroViewModel::TutorialMicroViewModel(
        int id,
        QString *name,
        QString *poster_src,
        TeacherMicroViewModel *teacherMicroViewModel,
        StyleMicroViewModel *styleMicroViewModel,
        int price,
        bool is_active,
        int order_in_list)
{
    this->id = id;
    this->name = name;
    this->poster_src = poster_src;
    this->teacherMicroViewModel = teacherMicroViewModel;
    this->styleMicroViewModel = styleMicroViewModel;
    this->price = price;
    this->is_active = is_active;
    this->order_in_list = order_in_list;
}
