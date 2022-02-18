#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include "config.h"
#include <QPushButton>


class widget2 : public QWidget
{
    Q_OBJECT
public:
    explicit widget2(QWidget *parent = nullptr);

    void windowset2();
    void _tryagain();


signals:

    void mysignal();

};

#endif // WIDGET2_H
