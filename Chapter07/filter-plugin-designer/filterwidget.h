#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>

namespace Ui {
class FilterWidget;
}

class FILTERPLUGINDESIGNERSHARED_EXPORT FilterWidget : public QWidget
{
    Q_OBJECT

    Q_ENUMS(FilterType)
    Q_PROPERTY(QString Title READ Title WRITE setTitle)
    Q_PROPERTY(FilterType filterType READ filterType WRITE setFilterType)

public:
    explicit FilterWidget(QWidget *parent = 0);
    ~FilterWidget();

    void process();
    void setSourcePicture(const QImage& sourcePicture);
    void updateThumbnail(const QImage& sourceThumbnail);

    QString title() const;
    FilterType filterType() const;

public slots:
    void setTitle(const QString& title);
    void setFilterType(const FilterType filterType);

signals:
    void pictureProcessed(const QImage& picture);

protected:
    void mousePressEvent(QMouseEvent*) override;

private:
    Ui::FilterWidget *ui;
    std::unique_ptr<Filter> mFilter;
    FilterType mFilterType;

    QImage mDefaultSourcePicture;
    QImage mSourcePicture;
    QImage mSourceThumbnail;

    QImage mFilteredPicture;
    QImage mFilteredThumbnail;

private:
    Ui::FilterWidget *ui;
};

#endif // FILTERWIDGET_H
