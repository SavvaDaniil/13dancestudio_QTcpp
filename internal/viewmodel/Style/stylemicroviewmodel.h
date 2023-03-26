#ifndef STYLEMICROVIEWMODEL_H
#define STYLEMICROVIEWMODEL_H

#include <qjsonobject.h>
#include <qstring.h>

class StyleMicroViewModel : public QJsonObject
{
public:
    StyleMicroViewModel(int id, QString name);
    int id;
    QString name;
};

#endif // STYLEMICROVIEWMODEL_H
