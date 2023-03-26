#include "teacherrepository.h"

#include <internal/data/applicationdbcontext.h>
#include <internal/factory/teacherfactory.h>

TeacherRepository::TeacherRepository()
{

}

Teacher *TeacherRepository::findById(qint64 id)
{

    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;
    //qDebug() << db.lastError().text();

    Teacher *teacher = nullptr;
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT id, name, ... FROM XXXXXXXXXXXXXXXXXXXXX WHERE id = :id ");
        query.bindValue(":id", id);
        query.exec();

        TeacherFactory teacherFactory;
        if(query.next()) {
            teacher = (teacherFactory.createFromQuery(query));
        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    delete applicationDbContext;

    return teacher;
}

QList<Teacher> *TeacherRepository::listAll()
{
    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;
    //qDebug() << db.lastError().text();

    QList<Teacher> *teachers = new QList<Teacher>();
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT id, name, ... FROM XXXXXXXXXXXXXXXXXXXXX ORDER BY order_in_list DESC ");
        query.exec();

        TeacherFactory teacherFactory;
        while(query.next()) {
            //Style style = (styleFactory.createFromQuery(query));
            teachers->append(*teacherFactory.createFromQuery(query));
        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    delete applicationDbContext;

    return teachers;
}
