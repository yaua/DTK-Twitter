#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineProfile>
#include <QLayout>
#include "webenginepage.h"
#include <DSpinner>

DWIDGET_USE_NAMESPACE
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QString yUrl = nullptr,
                    QWidget *parent = nullptr);
    ~Widget();
    QWebEnginePage *getPage();
    void goBack();
    void goForward();
    void refresh();
private:
    QWebEngineView *m_webEngineView;
    QString m_yUrl;
    DSpinner *m_spinner;
    QHBoxLayout *main;
    void clearLayout(QLayout *layout);
private slots:
    void on_loadStarted();
    void on_loadFinished();
};
#endif // WIDGET_H
