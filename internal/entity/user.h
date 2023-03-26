#ifndef USER_H
#define USER_H

#include <QDate>
#include <QString>

class User
{
public:
    int id;
    QString username;
    QString password;
    QString authKey;
    QString accessToken;
    int active;
    ...

    User();
    void setId(int id);
    void setUsername(QString username);
};

#endif // USER_H
