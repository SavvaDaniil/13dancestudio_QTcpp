#include "stylerepository.h"

#include <internal/data/applicationdbcontext.h>

#include <internal/factory/stylefactory.h>

StyleRepository::StyleRepository()
{

}

Style *StyleRepository::findById(qint64 id)
{
    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;
    //qDebug() << db.lastError().text();

    Style *style = nullptr;
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT id, name, ... FROM XXXXXXXXXXXXXXXXXXXXX WHERE id = :id ");
        query.bindValue(":id", id);
        query.exec();

        StyleFactory styleFactory;
        if(query.next()) {
            style = (styleFactory.createFromQuery(query));
        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    delete applicationDbContext;

    return style;
}

QList<Style> *StyleRepository::listAll()
{

    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;
    //qDebug() << db.lastError().text();

    QList<Style> *styles = new QList<Style>();
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT id, name, ... FROM XXXXXXXXXXXXXXXXXXXXX ORDER BY order_in_list DESC");
        query.exec();

        StyleFactory styleFactory;
        while(query.next()) {
            styles->append(*styleFactory.createFromQuery(query));
        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    delete applicationDbContext;

    return styles;
}
