#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>

namespace Ui {
class PictureWidget;
}

class PictureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PictureWidget(QWidget *parent = 0);
    ~PictureWidget();

private:
    Ui::PictureWidget *ui;
};

#endif // PICTUREWIDGET_H
