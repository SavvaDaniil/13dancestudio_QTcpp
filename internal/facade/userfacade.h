#ifndef USERFACADE_H
#define USERFACADE_H

#include "internal/repository/userrepository.h"
#include <internal/viewmodel/jsonanswerstatus.h>
#include <internal/dto/User/userlogindto.h>

class UserFacade
{
public:
    UserFacade();
    QJsonObject Login(UserLoginDTO userLoginDTO);

    static QString generateSalt();
    static QString hashPassword(const QString& password, const QString& salt);
private:
    UserRepository _userRepository;
    #define BCRYPT_HASHSIZE	(64)

    static void generateRandomBytes(char* outBuffer, int bufferSize);
};

#endif // USERFACADE_H
