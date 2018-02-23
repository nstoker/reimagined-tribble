#include <QImage>



/*!
 \brief The Filter class
 Based on code from Mastering Qt 5, Chapter 8.
 Let the bug hunting commence!
 */
class Filter
{
public:
    virtual ~Filter(){}
    virtual QString name() const = 0;
    virtual QImage process(const QImage& image) = 0;
};

/*! /define Filter_iid
  /brief The filter_iid is a unique identifier to let Qt know the interface name
*/
#define Filter_iid "org.lazyeightmedia.imageanimation.filters.Filter"
Q_DECLARE_INTERFACE(Filter, Filter_iid)

