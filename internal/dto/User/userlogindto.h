#ifndef USERLOGINDTO_H
#define USERLOGINDTO_H

#include <qstring.h>

class UserLoginDTO
{
public:
    UserLoginDTO(QString username, QString password);
    QString GetUsername();
    QString GetPassword();
private:
    QString username;
    QString password;

};

#endif // USERLOGINDTO_H
