#include "filterplugindesigner.h"
#include "filterwidget.h"


/*!
 * \brief FilterPluginDesigner::FilterPluginDesigner
 * \param parent
 */
FilterPluginDesigner::FilterPluginDesigner(QObject *parent) :
    QObject(parent),
    mInitialized(false)
{

}



/*!
 * \brief FilterPluginDesigner::createWidget
 * \param parent
 * \return
 */
QWidget* FilterPluginDesigner::createWidget(QWidget* parent)
{
    return new FilterWidget(parent);
}



/*!
 * \brief FilterPluginDesigner::group
 * \return
 */
QString FilterPluginDesigner::group() const
{
    return "Mastering Qt5";
}



/*!
 * \brief FilterPluginDesigner::name
 * \return
 */
QString FilterPluginDesigner::name() const
{
    return "FilterWidget";
}



/*!
 * \brief FilterPluginDesigner::toolTip
 * \return
 */
QString FilterPluginDesigner::toolTip() const
{
    return "A filtered picture";
}



/*!
 * \brief FilterPluginDesigner::whatsThis
 * \return
 */
QString FilterPluginDesigner::whatsThis() const
{
    return "The filter widget applies an image effect";
}



/*!
 * \brief FilterPluginDesigner::icon
 * \return
 */
QIcon FilterPluginDesigner::icon() const
{
    return QIcon(":/icon.jpg");
}



/*!
 * \brief FilterPluginDesigner::includeFile
 * \return
 */
QString FilterPluginDesigner::includeFile() const
{
    return "filterwidget.h";
}



/*!
 * \brief FilterPluginDesigner::initialize
 * \param core
 */
void FilterPluginDesigner::initialize(QDesignerFormEditorInterface *core)
{
    Q_UNUSED(core);

    if(mInitialized)
        return;

    mInitialized = true;
}



/*!
 * \brief FilterPluginDesigner::isContainer
 * \return
 */
bool FilterPluginDesigner::isContainer() const
{
    return false;
}



/*!
 * \brief FilterPluginDesigner::isInitialized
 * \return
 */
bool FilterPluginDesigner::isInitialized() const
{
    return mInitialized;
}
