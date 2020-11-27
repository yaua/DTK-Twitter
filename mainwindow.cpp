#include "mainwindow.h"
#include <DMainWindow>
#include <DTitlebar>
#include <QtWidgets/QVBoxLayout>
#include <DToolButton>

DWIDGET_USE_NAMESPACE

MainWindow::MainWindow(QString szTitle,
                       QString szUrl,
                       QWidget *parent)
    : DMainWindow(parent)
    , m_widget(nullptr)
{
    m_widget = new Widget(szUrl);
    MainWindow::resize(700,800);
    titlebar()->setTitle(szTitle);
    setCentralWidget(m_widget);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    titlebar()->setIcon(QIcon(":/images/logo.svg"));
    DToolButton *btnBack = new DToolButton(titlebar());
    btnBack->setIcon(QIcon(":/images/go-previous-24.svg"));
    btnBack->setIconSize(QSize(20, 20));
    DToolButton *btnForward = new DToolButton(titlebar());
    btnForward->setIcon(QIcon(":/images/go-next-24.svg"));
    btnForward->setIconSize(QSize(20, 20));
    DToolButton *btnRefresh = new DToolButton(titlebar());
    btnRefresh->setIcon(QIcon(":/images/view-refresh.svg"));
    btnRefresh->setIconSize(QSize(20, 20));
    connect(DGuiApplicationHelper::instance(), &DGuiApplicationHelper::themeTypeChanged,this,&MainWindow::setTheme);
    connect(btnBack, &DToolButton::clicked, this, [&]()
    {
        if (m_widget)
        {
            m_widget->goBack();
        }
    });
    connect(btnForward, &DToolButton::clicked, this, [&]()
    {
        if (m_widget)
        {
            m_widget->goForward();
        }
    });
    connect(btnRefresh, &DToolButton::clicked, this, [&]()
    {
        if (m_widget)
        {
            m_widget->refresh();
        }
    });

    titlebar()->addWidget(btnBack, Qt::AlignLeft);
    titlebar()->addWidget(btnForward, Qt::AlignLeft);
    titlebar()->addWidget(btnRefresh, Qt::AlignLeft);
}
MainWindow::~MainWindow()
{
    emit sigQuit();
    if (m_widget)
    {
        delete m_widget;
        m_widget = nullptr;
    }
}
void MainWindow::setTheme(DGuiApplicationHelper::ColorType theme)
{
    if(theme==DGuiApplicationHelper::LightType){
        qDebug()<<"Light";
    }else {
        qDebug()<<"Dark";
    }
}

