#include "widget.h"
#include <QWebEngineView>
#include "webenginepage.h"

Widget::Widget(QString yUrl, QWidget *parent)
    : QWidget(parent)
    , m_webEngineView(new QWebEngineView)
    , m_yUrl(yUrl)
    , m_spinner(new DSpinner) /*load with dtk cursor*/
    , main(new QHBoxLayout)
{
    m_spinner->setFixedSize(80, 80);
    setLayout(main);
    m_webEngineView->setObjectName(QStringLiteral("webEngineView"));
    m_webEngineView->setEnabled(true);
    m_webEngineView->setAutoFillBackground(false);
    m_webEngineView->setZoomFactor(1);
    WebEnginePage *page = new WebEnginePage;
    m_webEngineView->setPage(page);
    m_webEngineView->setUrl(QUrl(nullptr));
    if (!m_yUrl.isEmpty())
    {
        m_webEngineView->setUrl(QUrl(m_yUrl));
    }
    connect(m_webEngineView, &QWebEngineView::loadStarted, this, &Widget::on_loadStarted);
    connect(m_webEngineView, &QWebEngineView::loadFinished, this, &Widget::on_loadFinished);
}
Widget::~Widget()
{
}
QWebEnginePage *Widget::getPage()
{
    return this->m_webEngineView->page();
}
void Widget::goBack()
{
    m_webEngineView->back();
}
void Widget::goForward()
{
    m_webEngineView->forward();
}
void Widget::refresh()
{
    m_webEngineView->reload();
}
void Widget::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr)
    {
        delete item;
    }
}
void Widget::on_loadStarted()
{
    clearLayout(main);
    main->addStretch();
    main->addWidget(m_spinner);
    main->addStretch();
    m_spinner->start();
}
void Widget::on_loadFinished()
{
    m_spinner->stop();
    clearLayout(main);
    main->addWidget(m_webEngineView);
}
