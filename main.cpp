#include <QCoreApplication>
#include <QtCore>
#include <QtHttpServer>
#include <QHttpServerResponder>

#include <QtSql>
#include <QSqlDatabase>

#include <internal/controller/apistylecontroller.h>
#include <internal/controller/apitutorialcontroller.h>
#include <internal/controller/apiusercontroller.h>

#include <internal/facade/userfacade.h>
#include "internal/repository/userrepository.h"

QHttpServerResponse routeApi(){

    QJsonArray jsonAnswer = QJsonArray();

    QJsonObject statusValue = QJsonObject();
    statusValue.insert(QString("status"), QString("success"));
    jsonAnswer.append(statusValue);

    QString answerSting = QJsonDocument(statusValue).toJson(QJsonDocument::Compact).toStdString().c_str();

    return answerSting;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHttpServer httpServer;



    httpServer.route("/api/user/login", QHttpServerRequest::Method::Post, [](const QHttpServerRequest &request) {

        QJsonObject userLoginDTO = (QJsonDocument::fromJson(request.body())).object();

        if(userLoginDTO.contains("username") && userLoginDTO.contains("password")){
            UserFacade userFacade = UserFacade();
            QJsonObject jsonAnswerStatus = userFacade.Login(UserLoginDTO(userLoginDTO.value("username").toString(), userLoginDTO.value("password").toString()));
            return QHttpServerResponse(jsonAnswerStatus, QHttpServerResponder::StatusCode::Ok);
        }

        QJsonObject jsonAnswerStatus = QJsonObject(
        {
            qMakePair(QString("status"), QJsonValue("error")),
            qMakePair(QString("errors"), QJsonValue("no_data"))
        });
        return QHttpServerResponse(jsonAnswerStatus, QHttpServerResponder::StatusCode::BadRequest);
    });

    httpServer.route("/api/user/secret", QHttpServerRequest::Method::Get, [](const QHttpServerRequest &request) {
        ApiUserController apiUserController;
        return apiUserController.secret(request);
    });

    httpServer.route("/api/tutorial/search", QHttpServerRequest::Method::Post, [](const QHttpServerRequest &request) {
        ApiTutorialController apiTutorialController;
        return apiTutorialController.search(request, 0);
    });

    httpServer.route("/api/style/list_all_micro", QHttpServerRequest::Method::Post, [](const QHttpServerRequest &request) {
        ApiStyleController apiStyleController;
        return apiStyleController.listAllMicro(request);
    });


    httpServer.listen(QHostAddress::Any, 8081);

    return a.exec();
}


