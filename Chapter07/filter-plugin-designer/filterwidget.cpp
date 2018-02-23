#include "filterwidget.h"
#include "ui_filterwidget.h"
#include "filterblur.h"
#include "filtergrayscale.h"
#include "filteroriginal.h"


/*!
 * \brief FilterWidget::FilterWidget
 * \param parent
 */
FilterWidget::FilterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterWidget),
    mFilterType(Original),
    mDefaultSourcePicture(":/lenna.jpg"),
    mSourcePicture(),
    mSourceThumbnail(mDefaultSourcePicture.scaled(QSize(256,256),
                                                  Qt::KeepAspectRatio,
                                                  Qt::SmoothTransformation)),
    mFilteredPicture(),
    mFilteredThumbnail()
{
    ui->setupUi(this);
    setFilterType(Original);
}



/*!
 * \brief FilterWidget::~FilterWidget
 */
FilterWidget::~FilterWidget()
{
    delete ui;
}



/*!
 * \brief FilterWidget::process
 */
void FilterWidget::process()
{
   mFilteredPicture = mFilter->process(mSourcePicture);
   emit pictureProcessed(mFilteredPicture);
}


/*!
 * \brief FilterWidget::setSourcePicture
 * \param sourcePictures
 */
void FilterWidget::setSourcePicture(const QImage& sourcePictures)
{
    mSourcePicture = sourcePictures;
}



/*!
 * \brief FilterWidget::updateThumbnail
 * \param sourceThumbnail
 */
void FilterWidget::updateThumbnail(const QImage &sourceThumbnail)
{
    mSourceThumbnail = sourceThumbnail;
    mFilteredThumbnail = mFilter->process(mSourceThumbnail);
    QPixmap pixmap = QPixmap::fromImage(mFilteredThumbnail);
    ui->thumbnailLabel->setPixmap(pixmap);
}



/*!
 * \brief FilterWidget::setTitle
 * \param title
 */
void FilterWidget::setTitle(const QString &title)
{
    ui->titleLabel->setText(title);
}



/*!
 * \brief FilterWidget::setFilterType
 * \param filterType
 */
void FilterWidget::setFilterType(FilterWidget::FilterType filterType)
{
    if(filterType == mFilterType && mFilter)
    {
        return;
    }

    mFilterType = filterType;

    switch(filterType){
    case Original:
        mFilter = std::make_unique<FilterOriginal>();
        break;
    case Blur:
        mFilter = std::make_unique<FilterBlur>();
        break;
    case Grayscale:
        mFilter = std::make_unique<FilterGrayscale>();
        break;
    default:
        break;
    }

    updateThumbnail(mSourceThumbnail);
}



/*!
 * \brief FilterWidget::title
 * \return
 */
QString FilterWidget::title() const
{
    return ui->titleLabel->text();
}



/*!
 * \brief FilterWidget::filterType
 * \return
 */
FilterWidget::FilterType FilterWidget::filterType() const
{
    return mFilterType;
}



/*!
 * \brief FilterWidget::mousePressEvent
 */
void FilterWidget::mousePressEvent(QMouseEvent *)
{
    process();
}
