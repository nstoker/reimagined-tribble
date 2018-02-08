#include <QSqlQuery>
#include "picturedao.h"

void PictureDao::init() const
{
    if(!mDatabase.tables().contains("pictures")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE pictures ("
                           + "id INTEGER PRIMARY KEY AUTOINCREMENT"
                           + "album_id INTEGER, "
                           + "url TEXT)"
                           ));
    }
}
