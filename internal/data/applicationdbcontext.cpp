#include "applicationdbcontext.h"
#include "qdebug.h"

#include <QDateTime>

ApplicationDbContext::ApplicationDbContext()
{
    QDateTime qDateTime = QDateTime::currentDateTime();

    this->dbMysql = QSqlDatabase::addDatabase("XXXXXXXXXXXX", QString("Connection from: " + qDateTime.toString("yyyy-MM-dd HH:mm:ss")));
    this->dbMysql.setHostName("XXXXXXXXXXXX");
    this->dbMysql.setDatabaseName("XXXXXXXXXXXX");
    this->dbMysql.setUserName("XXXXXXXXXXXX");
    this->dbMysql.setPassword("XXXXXXXXXXXX");

    qDebug() << "Connection successfull";
}


QSqlDatabase *ApplicationDbContext::getConnectonToMysql()
{
    return &dbMysql;
}

void ApplicationDbContext::closeConnectonToMysql()
{
    this->dbMysql.close();
    this->dbMysql.removeDatabase("XXXXXXXXXXXX");
}

