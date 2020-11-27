#include "widget.h"
#include "ui_widget.h"
#include <QWebEngineView>
#include "webenginepage.h"

Widget::Widget(QString yUrl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
    , m_webEngineView(nullptr)
    , m_yUrl(yUrl)
{
    ui->setupUi(this);
    m_webEngineView = new QWebEngineView(this);
    m_webEngineView->setObjectName(QStringLiteral("webEngineView"));
    m_webEngineView->setEnabled(true);
    m_webEngineView->setAutoFillBackground(false);
    m_webEngineView->setProperty("url", QVariant(QUrl(QStringLiteral(""))));
    m_webEngineView->setProperty("zoomFactor", QVariant(1));
    ui->verticalLayout->addWidget(m_webEngineView);
    WebEnginePage *page = new WebEnginePage();
    m_webEngineView->setPage(page);

    if (!m_yUrl.isEmpty())
    {
        m_webEngineView->setUrl(QUrl(m_yUrl));
    }
}

Widget::~Widget()
{
    delete ui;
}
void Widget::goBack()
{
    if (m_webEngineView)
    {
        m_webEngineView->triggerPageAction(QWebEnginePage::Back);
    }
}
void Widget::goForward()
{
    if (m_webEngineView)
    {
        m_webEngineView->triggerPageAction(QWebEnginePage::Forward);
    }
}
void Widget::refresh()
{
    if (m_webEngineView)
    {
        m_webEngineView->triggerPageAction(QWebEnginePage::Reload);
    }
}
