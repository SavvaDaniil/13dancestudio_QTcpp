#include "tutorialpreviewviewmodel.h"

TutorialPreviewViewModel::TutorialPreviewViewModel(
    int id,
    QString name,
    QString poster_src,
    StyleMicroViewModel *styleMicroViewModel,
    TeacherMicroViewModel *teacherMicroViewModel,
    int price,
    bool is_active,
    int order_in_list
)
{
    this->insert(QString("id"), QJsonValue(id));
    this->insert(QString("name"), QJsonValue(name));
    this->insert(QString("poster_src"), QJsonValue(poster_src));
    if(styleMicroViewModel != nullptr){
        this->insert(QString("styleMicroViewModel"), QJsonValue(*styleMicroViewModel));
    }
    if(teacherMicroViewModel != nullptr){
        this->insert(QString("teacherMicroViewModel"), QJsonValue(*teacherMicroViewModel));
    }
    this->insert(QString("price"), QJsonValue(price));
    this->insert(QString("is_active"), QJsonValue(is_active));
    this->insert(QString("order_in_list"), QJsonValue(order_in_list));

}

