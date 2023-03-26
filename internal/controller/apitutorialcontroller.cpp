#include "apitutorialcontroller.h"
#include <internal/facade/tutorialfacade.h>
#include <qjsonarray.h>
#include <qjsonobject.h>

ApiTutorialController::ApiTutorialController()
{

}

QHttpServerResponse ApiTutorialController::search(const QHttpServerRequest &request, int skip)
{
    TutorialFacade tutorialFacade;
    //QList<TutorialPreviewViewModel> tutorialPreviewViewModels = tutorialFacade.search(skip, 0);
    QJsonArray tutorialPreviewViewModels = tutorialFacade.search(skip, 0);
    //qDebug() << "tutorialPreviewViewModels.count(): " << tutorialPreviewViewModels.count();

    QJsonObject jsonAnswerStatus = QJsonObject(
    {
        qMakePair(QString("status"), QJsonValue("success")),
        qMakePair(QString("tutorialPreviewViewModels"), tutorialPreviewViewModels),
    });
    return QHttpServerResponse(jsonAnswerStatus, QHttpServerResponder::StatusCode::Ok);
}
