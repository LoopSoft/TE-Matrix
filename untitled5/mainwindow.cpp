#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtAdMob/QtAdMobBanner.h"
#include "QtAdMob/QtAdMobInterstitial.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    properties.setWindow(this);
    properties.setCentralWidget(ui->widget);
    properties.setTitle("Sinal de Controle");
    properties.setxLabel("Tempo em segundos");
    properties.setyLabel("Amplitude em unidades de engenharia");
    properties.setPlotSize(0,0, 400, 300);
    properties.font        = "Helvetica";
    this->grafic = new PlotHandler::plot<double>(X,Y,this->properties);
    this->generatePlot();

    //Contador para função update (identifica a orientação do dispositivo)
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateBannerPos()));
    timer->start(1000);

    this->setupBanner();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent( QKeyEvent * event ){

    if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        /*if(ui->Command->text() != "")
        {
            if(MI.identifyEquality(ui->Command->text().toStdString())){
                std::string str;
                str = MI.AtributeEquality(ui->Command->text().toStdString());
                std::string str2;
                str2 << MI.find(str);
                str += " = ";
                ui->console->append(str.c_str());
                ui->console->append(str2.c_str());
            }
            else{
                std::string str = ui->Command->text().toStdString() + " =\n";
                str << MI.Operation(ui->Command->text().toStdString());
                ui->console->append(str.c_str());
            }
            ui->Command->setText("");
        }*/
        if(ui->x->text() != "" || ui->y->text() != "")
        {
            this->generatePlot();

        }
    }
}

void MainWindow::generatePlot()
{
    /*
    properties.setWindow(this);
    properties.setCentralWidget(ui->widget);
    //properties.setTitle("Sinal de Controle");
    properties.setTitle(ui->x->text().toStdString().c_str());
    properties.setxLabel("Tempo em segundos");
    properties.setyLabel("Amplitude em unidades de engenharia");
    properties.setPlotSize(0,0, 400, 300);
    properties.font        = "Helvetica";
*/

    X = ui->x->text().toStdString().c_str();
    Y = ui->y->text().toStdString().c_str();
//  this->grafic->generalPlot(X,Y);
    ui->tab_2->hide();
    this->grafic = new PlotHandler::plot<double>(X,Y,this->properties);
    ui->tab_2->show();
}

void MainWindow::setupBanner()
{
    m_Banner = CreateQtAdMobBanner();
    m_Banner->Initialize();
    m_Banner->SetUnitId("ca-app-pub-2682585457279581/8054389559");
    m_Banner->SetSize(IQtAdMobBanner::Banner);
    //m_Banner->AddTestDevice("514ED2E95AD8EECE454CC5565326160A");
    m_Banner->Show();
}

void MainWindow::updateBannerPos()
{
    //Teste, pegando a resolução da tela e jogando num lineEdit pra visualizar o valor
    //QString qstr = QString::number(geometry().width());
    //ui->x->setText(qstr);

    posY = geometry().bottom() - 5;
    posX = geometry().center().x() - (m_Banner->GetSizeInPixels().width()/2);

    QPoint position(posX, posY);
    m_Banner->SetPosition(position);
}
