#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DGuiApplicationHelper>
#include <DMainWindow>
#include "widget.h"

#include "globaldefine.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString yTitle = DEFAULT_TITLE,
               QString yUrl = DEFAULT_URL,
               QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sigQuit();

private:
    Widget *m_widget;
    void setTheme(DGuiApplicationHelper::ColorType);
};

#endif // MAINWINDOW_H
