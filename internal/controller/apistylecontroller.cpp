#include "apistylecontroller.h"

#include <internal/repository/stylerepository.h>
#include <internal/viewmodel/Style/stylemicroviewmodel.h>

ApiStyleController::ApiStyleController()
{

}

QHttpServerResponse ApiStyleController::listAllMicro(const QHttpServerRequest &request)
{
    StyleRepository styleRepository;
    QList<Style> *styles = styleRepository.listAll();

    QList<QJsonObject> styleMicroViewModelAsJsonObjects;
    QList<Style>::Iterator stylesIterator;
    for(stylesIterator = styles->begin(); stylesIterator != styles->end(); ++stylesIterator){
        Style style = *stylesIterator;
        qDebug() << "style.name: " << style.name;
    }

    QJsonObject jsonAnswerStatus = QJsonObject(
    {
        qMakePair(QString("status"), QJsonValue("success")),
    });
    return QHttpServerResponse(jsonAnswerStatus, QHttpServerResponder::StatusCode::Ok);

}
