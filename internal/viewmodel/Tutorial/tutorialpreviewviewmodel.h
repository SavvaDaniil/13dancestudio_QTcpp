#ifndef TUTORIALPREVIEWVIEWMODEL_H
#define TUTORIALPREVIEWVIEWMODEL_H

#include <qstring.h>
#include <internal/viewmodel/Teacher/teachermicroviewmodel.h>
#include <internal/viewmodel/Style/stylemicroviewmodel.h>

class TutorialPreviewViewModel : public QJsonObject
{
public:
    TutorialPreviewViewModel();
    TutorialPreviewViewModel(
        int id,
        QString name,
        QString poster_src,
        StyleMicroViewModel *styleMicroViewModel,
        TeacherMicroViewModel *teacherMicroViewModel,
        int price,
        bool is_active,
        int order_in_list
    );

};

#endif // TUTORIALPREVIEWVIEWMODEL_H
