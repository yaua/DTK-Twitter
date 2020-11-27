#include "mainwindow.h"
#include <DApplication>
#include <DWidgetUtil>
#include <DAboutDialog>
#include <DMainWindow>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QTranslator>
#include <QFileInfo>
#include <QSettings>
#include "globaldefine.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication a(argc, argv);
    DAboutDialog dialog;
    a.loadTranslator();
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setApplicationName(DEFAULT_TITLE);
    a.setProductName(DEFAULT_TITLE);
    a.setAboutDialog(&dialog);
    dialog.setWindowTitle(DEFAULT_TITLE);
    dialog.setProductName(QString("<span>%1</span>").arg(DEFAULT_TITLE));
    dialog.setProductIcon(QIcon(":/images/logo.svg"));
    dialog.setCompanyLogo(QPixmap(":/images/logo.png"));
    QString szDefaultDesc = QString("<span style=' font-size:8pt; font-weight:600;'>Deepin </span>"
                                    "<a href='https://deepinenespañol.org'>https://deepinenespañol.org</a><br/>"
                                    "<span style=' font-size:8pt; font-weight:600;'>This is the simple app with dtk webview</span>");
    dialog.setDescription(szDefaultDesc);
    dialog.setVersion(DApplication::buildVersion(QString("%1 %2").arg(QObject::tr("Version")).arg("1.1.0")));
    QString yTitle = DEFAULT_TITLE;
    QString yUrl = DEFAULT_URL;
    MainWindow w(yTitle, yUrl);
    w.show();
    Dtk::Widget::moveToCenter(&w);
    return a.exec();
}
