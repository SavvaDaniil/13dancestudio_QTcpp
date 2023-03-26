#ifndef TUTORIALFACADE_H
#define TUTORIALFACADE_H

#include <internal/viewmodel/Tutorial/tutorialpreviewviewmodel.h>

#include <internal/entity/style.h>
#include <internal/entity/teacher.h>
#include <internal/entity/tutorial.h>


class TutorialFacade
{
public:
    TutorialFacade();
    //QList<TutorialPreviewViewModel> search(int skip, int userId);
    QJsonArray search(int skip, int userId);
    TutorialPreviewViewModel toPreviewViewModel(Tutorial *tutorial, StyleMicroViewModel *styleMicroViewModel, TeacherMicroViewModel *teacherMicroViewModel);
    QString getPosterSrc(int tutorialId);
};

#endif // TUTORIALFACADE_H
