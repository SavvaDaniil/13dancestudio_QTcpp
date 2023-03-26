#include "apiusercontroller.h"

#include <internal/middleware/usermiddleware.h>

ApiUserController::ApiUserController()
{

}

QHttpServerResponse ApiUserController::secret(const QHttpServerRequest &request)
{
    UserMiddleware userMiddleware;
    int userId = userMiddleware.parseJwtAndGetUserId(request, false);

    if(userId == 0){
        QJsonObject jsonAnswerStatus = QJsonObject(
        {
            qMakePair(QString("status"), QJsonValue("error")),
            qMakePair(QString("errors"), QJsonValue("not_auth"))
        });
        return QHttpServerResponse(jsonAnswerStatus, QHttpServerResponder::StatusCode::Unauthorized);
    }

    QJsonObject jsonAnswerStatus = QJsonObject(
    {
        qMakePair(QString("status"), QJsonValue("success"))
    });
    return QHttpServerResponse(jsonAnswerStatus, QHttpServerResponder::StatusCode::Ok);
}
