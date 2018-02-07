#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>



#include "album.h"
#include "albumdao.h"
#include "databasemanager.h"



AlbumDAO::AlbumDAO(QSqlDatabase& database) :
    mDatabase(database)
{

}



void AlbumDAO::init() const
{
    if(!mDatabase.tables().contains("albums")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMEMT, name TEXT");
    }
}



void AlbumDAO::addAlbum(Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());
}



QVector<Album*> AlbumDAO::albums() const
{
    QSqlQuery query("SELECT * FROM albums", mDatabase);
    query.exec();
    QVector<Album*> list;
    while(query.next()) {
        Album* album = new Album();
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        list.append(album);
    }

    return list;
}
