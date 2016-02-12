#include "mainwindow.h"
#include "splash.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QSplashScreen *spsc = new QSplashScreen;
    QPixmap p(":/imgs/Logo/SplashScreen.png");
    spsc->setPixmap(p);
    //spsc->adjustSize();
    spsc->show();


    MainWindow w;

    QTimer::singleShot(2500, spsc, SLOT(close()));
    QTimer::singleShot(2500, &w, SLOT(showFullScreen()));


    //Splash sp;
    //sp.show();

    return a.exec();
}
