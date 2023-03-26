#include "usermiddleware.h"

UserMiddleware::UserMiddleware()
{

}

int UserMiddleware::parseJwtAndGetUserId(const QHttpServerRequest &request, bool isNeedDebug)
{
    QList<QPair<QByteArray, QByteArray>> headersList = request.headers();
    for (int i=0; i < headersList.count(); i++){
        QPair<QByteArray, QByteArray> headerPair = headersList.at(i);
        //qDebug() << headerPair.first << " " << headerPair.second;
        if(QString(headerPair.first).contains("Authorization")){
            QString bearerToken = QString(headerPair.second);
            bearerToken.replace("Bearer ", "");
            if(isNeedDebug)qDebug() << "bearerToken: " << bearerToken;

            if(bearerToken.isEmpty())break;

            QStringList listJwtParts = bearerToken.split(".");
            if (listJwtParts.count() == 3)
            {
                QJsonWebToken token = QJsonWebToken::fromTokenAndSecret(bearerToken, this->jwtSecret);

                //QString strHeader = token.getHeaderQStr();
                QString strPayload = token.getPayloadQStr();
                if (token.isValid())
                {
                    if(isNeedDebug)qDebug() << "jwt is VALID strPayload: " << strPayload;
                    QJsonDocument jsonResponse = QJsonDocument::fromJson(strPayload.toUtf8());
                    QJsonObject jsonObject = jsonResponse.object();
                    if(isNeedDebug)qDebug() << "jsonObject[\"sub\"].toInt(): " << jsonObject["sub"].toInt();
                    return jsonObject["sub"].toInt();
                }
                else
                {
                    if(isNeedDebug)qDebug() << "jwt is INVALID";
                }
            }
        }
    }

    return 0;
}

