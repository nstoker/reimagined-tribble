#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>



DatabaseManager& DatabaseManager::instance()
{
#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
    QFile assetDbFile(":/database/" + DATABASE_FILENAME);
    QString destinationDbFile = QStandardPaths::writableLocation(
                QStandardPaths::AppLocalDataLocation).append("/" + DATABASE_FILENAME);

    if(!QFile::exists(destinationDbFile)) {
        assetDbFile.copy(destinationDbFile);
        QFile::setPermissions(destinationDbFile, QFile::writeOwner | QFile::ReadOwner);
    }
    static DatabaseManager singleton(destinationDbFile);
#else
    static DatabaseManager singleton;
#endif

    return singleton;
}



DatabaseManager::DatabaseManager(const QString &path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    albumDao(*mDatabase),
    pictureDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);
    mDatabase->open();

    albumDao.init();
    pictureDao.init();
}



DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
}



void DatabaseManager::debugQuery(const QSqlQuery &query)
{
    if(query.lastError().type() == QSqlError::ErrorType::NoError){
        qDebug() << "Query OK:" << query.lastQuery();
    } else {
        qWarning() << "Query KO:" << query.lastError().text();
        qWarning() << "Query   :" << query.lastQuery();
    }
}
