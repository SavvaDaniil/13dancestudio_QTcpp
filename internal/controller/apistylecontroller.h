#ifndef APISTYLECONTROLLER_H
#define APISTYLECONTROLLER_H

#include <qhttpserverrequest.h>
#include <qhttpserverresponse.h>

class ApiStyleController
{
public:
    ApiStyleController();
    QHttpServerResponse listAllMicro(const QHttpServerRequest &request);
};

#endif // APISTYLECONTROLLER_H
