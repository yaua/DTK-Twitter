#include "mainwindow.h"
#include <DApplication>
#include <DWidgetUtil>
#include <DAboutDialog>
#include <DMainWindow>
#include <QFileInfo>
#include <QSettings>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setProductName(DEFAULT_TITLE);
    DAboutDialog *dialog = new DAboutDialog;
    a.setAboutDialog(dialog);
    dialog->setProductIcon(QIcon(":/images/twitter.svg"));
    QString yDefaultDesc = QString("<span style=' font-size:8pt; font-weight:600;'>This is the simple app with dtk lib and WebApp Runtime. Customize by yaua</span>");
    dialog->setDescription(yDefaultDesc);
    dialog->setVersion(DApplication::buildVersion(QString("%1 %2").arg(QObject::tr("Version")).arg("1.2.2")));
    dialog->setLicense(QObject::tr("This program is open source under GPLv3"));
    QString yTitle = DEFAULT_TITLE;
    QString yUrl = DEFAULT_URL;
    int width = DEFAULT_WIDTH;
    int height = DEFAULT_HEIGHT;
    bool tray = true;
    bool hideButtons = false;
    a.setQuitOnLastWindowClosed(!tray);
    MainWindow w(yTitle, yUrl, width, height, tray, hideButtons);
    w.show();
    return a.exec();
}
