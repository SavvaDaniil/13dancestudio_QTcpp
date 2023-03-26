#include "tutorialfacade.h"

#include <internal/repository/stylerepository.h>
#include <internal/repository/teacherrepository.h>
#include <internal/repository/tutorialrepository.h>

#include <internal/factory/stylefactory.h>
#include <internal/factory/teacherfactory.h>

TutorialFacade::TutorialFacade()
{

}

//QList<TutorialPreviewViewModel> TutorialFacade::search(int skip, int userId)
QJsonArray TutorialFacade::search(int skip, int userId)
{
    StyleRepository styleRepository;
    QList<Style> *styles = styleRepository.listAll();
    //Style *styleConnected = nullptr;
    StyleMicroViewModel *styleMicroViewModel = nullptr;
    StyleFactory styleFactory;
    /*
    qDebug() << "styles.count(): " << styles->count();
    QList<Style>::Iterator stylesIterator;
    for(stylesIterator = styles->begin(); stylesIterator != styles->end(); ++stylesIterator){
        Style style = (*stylesIterator);
        qDebug() << "style.id: " << style.id;
    }
    */

    TeacherRepository teacherRepository;
    QList<Teacher> *teachers = teacherRepository.listAll();
    //Teacher *teacherConnected = nullptr;
    TeacherMicroViewModel *teacherMicroViewModel = nullptr;
    TeacherFactory teacherFactory;

    TutorialRepository tutorialRepository;
    QList<Tutorial> *tutorials = tutorialRepository.search(skip);

    //QList<TutorialPreviewViewModel> tutorialPreviewViewModels;
    QJsonArray qJsonArrayAnswer;
    QList<Tutorial>::Iterator tutorialsIterator;
    for(tutorialsIterator = tutorials->begin(); tutorialsIterator != tutorials->end(); ++tutorialsIterator){
        Tutorial tutorial = (*tutorialsIterator);
        //qDebug() << "tutorial.id: " << tutorial.id << "tutorial.name: " << tutorial.name;


        //styleConnected = nullptr;
        styleMicroViewModel = nullptr;
        if(styles != nullptr && tutorial.styleId != 0){
            QList<Style>::Iterator stylesIterator;
            for(stylesIterator = styles->begin(); stylesIterator != styles->end(); ++stylesIterator){
                Style styleFromDb = (*stylesIterator);
                if(tutorial.styleId == styleFromDb.id){
                    //styleMicroViewModel = new StyleMicroViewModel(styleFromDb.id, &styleFromDb.name);
                    //styleConnected = &styleFromDb;
                    styleMicroViewModel = styleFactory.toMicroViewModel(styleFromDb);
                }
            }
        }


        teacherMicroViewModel = nullptr;
        if(teachers != nullptr && tutorial.teacherId != 0){
            QList<Teacher>::Iterator teachersIterator;
            for(teachersIterator = teachers->begin(); teachersIterator != teachers->end(); ++teachersIterator){
                Teacher teacherFromDb = (*teachersIterator);
                if(tutorial.styleId == teacherFromDb.id){
                    teacherMicroViewModel = teacherFactory.toMicroViewModel(teacherFromDb);
                }
            }
        }

        TutorialPreviewViewModel tutorialPreviewViewModel = this->toPreviewViewModel(
            &tutorial,
            styleMicroViewModel,
            teacherMicroViewModel
        );
        //qDebug() << "tutorialPreviewViewModel.name: " << *tutorialPreviewViewModel.name;

        //tutorialPreviewViewModels.append(tutorialPreviewViewModel);
        qJsonArrayAnswer.append(tutorialPreviewViewModel);
    }

    delete styles;
    delete styleMicroViewModel;
    delete teachers;
    delete tutorials;

    return qJsonArrayAnswer;
}

TutorialPreviewViewModel TutorialFacade::toPreviewViewModel(Tutorial *tutorial, StyleMicroViewModel *styleMicroViewModel, TeacherMicroViewModel *teacherMicroViewModel)
{
    /*
    StyleMicroViewModel *styleMicroViewModel = nullptr;
    if(style != nullptr)styleMicroViewModel = new StyleMicroViewModel(style->id, &style->name);
    TeacherMicroViewModel *teacherMicroViewModel = nullptr;
    if(teacher != nullptr)teacherMicroViewModel = new TeacherMicroViewModel(teacher->id, &teacher->name);
    */

    //qDebug() << "TutorialFacade::toPreviewViewModel name: " << tutorial->name;

    return TutorialPreviewViewModel(
        tutorial->id,
        tutorial->name,
        this->getPosterSrc(tutorial->id),
        styleMicroViewModel,
        teacherMicroViewModel,
        tutorial->price,
        false,
        tutorial->orderInList
    );
}

QString TutorialFacade::getPosterSrc(int tutorialId)
{
    QString currentFolder(qApp->applicationDirPath());
    //qDebug() << "App path : " << qApp->applicationDirPath();
    QString posterPath("/static/uploads/tutorial/" + QString::number(tutorialId) + ".jpg");
    //qDebug() << posterPath;
    //QFile posterFile(posterPath);
    QFileInfo fileInfo(currentFolder + posterPath);
    //qDebug() << fileInfo.filePath();
    if(fileInfo.exists()){
        return posterPath;
    }
    return QString();
}
