#include "stdafx.h"
#include "ZigbeeLaserRange.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication Qt_APP(argc, argv);
    ZigbeeLaserRange LaserWindow;
    LaserWindow.show();
    return Qt_APP.exec();
}
