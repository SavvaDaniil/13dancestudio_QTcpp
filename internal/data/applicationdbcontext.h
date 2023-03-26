#ifndef APPLICATIONDBCONTEXT_H
#define APPLICATIONDBCONTEXT_H

#include <QSqlDatabase>

class ApplicationDbContext
{
private:
    QSqlDatabase dbMysql;
public:
    ApplicationDbContext();
    QSqlDatabase *getConnectonToMysql();
    void closeConnectonToMysql();
};

#endif // APPLICATIONDBCONTEXT_H
