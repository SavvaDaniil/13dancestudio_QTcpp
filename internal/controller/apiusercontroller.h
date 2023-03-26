#ifndef APIUSERCONTROLLER_H
#define APIUSERCONTROLLER_H

#include <QtHttpServer>

class ApiUserController
{
public:
    ApiUserController();
    QHttpServerResponse secret(const QHttpServerRequest &request);
};

#endif // APIUSERCONTROLLER_H
