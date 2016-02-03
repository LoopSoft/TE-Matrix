#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/graphicLibs/plot.h"
#include "matrixinterface.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

//QT Admob
class IQtAdMobBanner;
class IQtAdMobInterstitial;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);
private:
    Ui::MainWindow *ui;
    LinAlg::Matrix<double> A,B,X,Y;
    PlotHandler::plot<double> *grafic;
    PlotHandler::plotProperties properties;
    MatrixInterface MI;

    IQtAdMobBanner* m_Banner;
    IQtAdMobInterstitial* m_Interstitial;
    bool m_Switch;
};

#endif // MAINWINDOW_H
