#pragma once

#include <QtWidgets/QWidget>

class QTabBar;
class TabBarWindow : public QWidget
{
    Q_OBJECT
public:
    TabBarWindow(QWidget *parent = Q_NULLPTR);
    ~TabBarWindow();

private:
    QTabBar* tabbar;
};
