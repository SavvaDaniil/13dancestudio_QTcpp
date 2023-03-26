#include "tutorialrepository.h"

#include <internal/data/applicationdbcontext.h>
#include <internal/factory/tutorialfactory.h>

TutorialRepository::TutorialRepository()
{

}

Tutorial *TutorialRepository::findById(int id)
{

    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;
    //qDebug() << db.lastError().text();

    Tutorial *tutorial = nullptr;
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT id, name, days, price, status, ... FROM XXXXXXXXXXXXXXXXXXXXX WHERE id = :id ");
        query.bindValue(":id", id);
        query.exec();

        TutorialFactory tutorialFactory;
        if(query.next()) {
            tutorial = (tutorialFactory.createFromQuery(query));
        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    delete applicationDbContext;

    return tutorial;
}

QList<Tutorial> *TutorialRepository::search(int skip)
{

    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;
    //qDebug() << db.lastError().text();

    QList<Tutorial> *tutorials = new QList<Tutorial>();
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT id, name, days, price, status, ... FROM XXXXXXXXXXXXXXXXXXXXX ORDER BY order_in_list DESC ");
        query.exec();

        TutorialFactory tutorialFactory;
        while(query.next()) {
            tutorials->append(*tutorialFactory.createFromQuery(query));
        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    delete applicationDbContext;

    return tutorials;
}
