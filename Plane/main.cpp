#include "widget.h"

#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //注册rcc
    QResource::registerResource(RCC);

    Widget w;
    w.show();
    return a.exec();
}
