#ifndef TUTORIALREPOSITORY_H
#define TUTORIALREPOSITORY_H

#include <internal/entity/tutorial.h>
#include <qlist.h>


class TutorialRepository
{
public:
    TutorialRepository();
    Tutorial *findById(int id);
    QList<Tutorial> *search(int skip);
};

#endif // TUTORIALREPOSITORY_H
