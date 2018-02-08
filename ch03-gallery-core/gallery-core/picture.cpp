#include "picture.h"

Picture::Picture(const QString &filePath) :
    Picture(QUrl::fromLocalFIle(filePath))
{

}



Picture::Picture(const QUrl &fileUrl) :
    mId(-1),
    mAlbumId(-1),
    mFileUrl(fileUrl)
{

}



QUrl Picture::fileUrl() const
{
    return mFileUrl;
}



QUrl Picture::setFileUrl(const QUrl &fileUrl)
{
    mFileUrl = fileUrl;
}


