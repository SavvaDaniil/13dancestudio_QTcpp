#include "userlogindto.h"


UserLoginDTO::UserLoginDTO(QString username, QString password)
{
    this->username = username;
    this->password = password;
}

QString UserLoginDTO::GetUsername()
{
    return this->username;
}

QString UserLoginDTO::GetPassword()
{
    return this->password;
}
