#include "mainwindow.h"

#include <QApplication>
#include <QtCore>

class Simpletimer
{
private:
    QTime creation_time;
public:
    Simpletimer() { creation_time = QTime::currentTime();}
    int GetAppLifeTime()
    {
        return creation_time.secsTo(QTime::currentTime());
    }
};

int main(int argc, char *argv[])
{
    Simpletimer alpha;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        if (alpha.GetAppLifeTime() >= 10) { // >= вместо ==
            QApplication::quit();
        }
    });
    timer.start(500);
    return QCoreApplication::exec();
}
