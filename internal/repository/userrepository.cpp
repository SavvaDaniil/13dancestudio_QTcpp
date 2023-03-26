#include "userrepository.h"
#include "internal/factory/userfactory.h"

UserRepository::UserRepository()
{

}

User *UserRepository::findById(qint64 id)
{
    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;
    //qDebug() << db.lastError().text();

    User *user = nullptr;
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT * FROM XXXXXXXXXXXXXXXXXXXXX WHERE id = :id ");
        query.bindValue(":id", id);
        query.exec();

        UserFactory userFactory;
        if(query.next()) {
            //qint64 userId = query.value(0).toInt();
            //QString username = query.value(1).toString();
            //qDebug() << db.lastError();

            user = (userFactory.createFromQuery(query));
            //user->setId(userId);
            //user->setUsername(username);

        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    /*
    if (applicationDbContext->getConnectonToMysql()->isOpen() ) {
        //std::cout << "the database is:  open" << std::endl;
    } else {
        //std::cout << "the database is:  Closed" << std::endl;
    }
    */
    delete applicationDbContext;

    return user;
}

User *UserRepository::findByUsername(QString username)
{
    ApplicationDbContext *applicationDbContext = new ApplicationDbContext();
    bool ok = applicationDbContext->getConnectonToMysql()->open();
    qDebug() << "is connection to db successfull: " << ok;

    User *user = nullptr;
    {
        QSqlQuery query(*(applicationDbContext->getConnectonToMysql()));
        query.prepare("SELECT * FROM XXXXXXXXXXXXXXXXXXXXX WHERE username = :username ");
        query.bindValue(":username", username);
        query.exec();

        UserFactory userFactory;
        if(query.next()) {
            user = (userFactory.createFromQuery(query));
        }
        query.clear();
    }

    applicationDbContext->closeConnectonToMysql();
    delete applicationDbContext;

    return user;
}

QList<User> *UserRepository::listAll()
{

    return nullptr;
}
