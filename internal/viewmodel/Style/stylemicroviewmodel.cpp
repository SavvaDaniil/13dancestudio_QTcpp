#include "stylemicroviewmodel.h"


StyleMicroViewModel::StyleMicroViewModel(int id, QString name)
{
    this->insert(QString("id"), QJsonValue(id));
    this->insert(QString("name"), QJsonValue(name));
}

