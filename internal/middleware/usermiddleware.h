#ifndef USERMIDDLEWARE_H
#define USERMIDDLEWARE_H

#include <qstring.h>
#include <QtHttpServer>
#include <lib/qjsonwebtoken/qjsonwebtoken.h>

class UserMiddleware
{
public:
    UserMiddleware();
    int parseJwtAndGetUserId(const QHttpServerRequest &request, bool isNeedDebug);
private:
    const QString jwtSecret = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
};

#endif // USERMIDDLEWARE_H
