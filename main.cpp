#include "clock.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain("xinhuang");
    QCoreApplication::setOrganizationName("xinhuang");
    QCoreApplication::setApplicationName("Clock");
    QCoreApplication::setApplicationVersion("1.0.0");

    Clock w;
    w.setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    w.show();

    return a.exec();
}
