#ifndef APITUTORIALCONTROLLER_H
#define APITUTORIALCONTROLLER_H

#include <QHttpServerResponse>


class ApiTutorialController
{
public:
    ApiTutorialController();
    QHttpServerResponse search(const QHttpServerRequest &request, int skip);
};

#endif // APITUTORIALCONTROLLER_H
