#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("QT Calibrator");      // Window name
    w.setFixedSize(930,720);                // Set a fixed size
    w.show();                               // Show the window
    return a.exec();
}
