#ifndef USERPROFILEVIEWMODEL_H
#define USERPROFILEVIEWMODEL_H

#include <qstring.h>



class UserProfileViewModel
{
private:
    int id;
    QString username;
public:
    UserProfileViewModel(int id, QString username);
};

#endif // USERPROFILEVIEWMODEL_H
