#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <DMainWindow>
#include <DToolButton>
#include <DProgressBar>
#include <DPushButton>
#include <DFloatingMessage>
#include <QSystemTrayIcon>
#include <QLayout>
#include <QProcess>
#include "widget.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    MainWindow(QString yTitle,
               QString yUrl,
               int nWidth,
               int nHeight,
               bool tray = false,
               bool nHideButtons = false,
               QWidget *parent = nullptr);
    ~MainWindow();
    void setIcon(QString yIconPath);
private:
    Widget *m_widget;
    QSystemTrayIcon *m_tray;
    DToolButton *btnBack;
    DToolButton *btnForward;
    DToolButton *btnRefresh;
    QMenu *m_menu;
    QAction *m_hideButtons;
    QMenu *t_menu;
    QAction *t_show;
    QAction *t_exit;
    QWidget *downloadProgressBar;
    DProgressBar *bar;
    DPushButton *pause;
    DPushButton *resume;
    DPushButton *cancel;
    QHBoxLayout *progress;
    DFloatingMessage *message;
    QProcess *process;
    bool isCanceled;
    bool mtray;
    int m_width, m_height;
    void hideButtons();
    QString saveAs(QString fileName);
private slots:
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_downloadStart(QWebEngineDownloadItem *item);
    void on_downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void on_downloadFinish(QString filePath);
    void on_downloadPause(QWebEngineDownloadItem *item);
    void on_downloadResume(QWebEngineDownloadItem *item);
    void on_downloadCancel(QWebEngineDownloadItem *item);
signals:
    void sigQuit();
};
#endif // MAINWINDOW_H
