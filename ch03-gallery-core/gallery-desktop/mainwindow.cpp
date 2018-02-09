#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStackedWidget>
#include <QItemSelectionModel>

#include "GalleryWidget.h"
#include "PictureWidget.h"
#include "AlbumModel.h"
#include "PictureModel.h"
#include "ThumbnailProxyModel.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AlbumModel* albumModel = new AlbumModel(this);
    QItemSelectionModel* albumSelectionModel = new QItemSelectionModel(albumModel, this);
    mGalleryWidget->setAlbumModel(albumModel);
    mGalleryWidget->setAlbumSelectionModel(albumSelectionModel);

    PictureModel* pictureModel = new PictureModel(*albumModel, this);
    ThumbnailProxyModel* thumbnailModel = new ThumbnailProxyModel(this);
    thumbnailModel->setSourceModel(pictureModel);

    QItemSelectionModel* pictureSelectionModel = new QItemSelectionModel(pictureModel, this);

    mGalleryWidget->setPictureModel(thumbnailModel);
    mGalleryWidget->setPictureSelectionModel(pictureSelectionModel);
    mPictureWidget->setModel(thumbnailModel);
    mPictureWidget->setSelectionModel(pictureSelectionModel);
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::displayGallery()
{
    mStackedWidget->setCurrentWidget(mGalleryWidget);
}



void MainWindow::displayPicture(const QModelIndex &index)
{
    Q_UNUSED(index);

    mStackedWidget->setCurrentWidget(mPictureWidget);
}
