#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtAdMob/QtAdMobBanner.h"
#include "QtAdMob/QtAdMobInterstitial.h"

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
    properties.setPlotSize(0,0,400,300);
    properties.font        = "Helvetica";

    m_Banner = CreateQtAdMobBanner();
    m_Banner->Initialize();
    m_Banner->SetUnitId("ca-app-pub-7485900711629006/8288667458");
    m_Banner->SetSize(IQtAdMobBanner::FullBanner);
    QPoint position(0, screen.geometry().height() - m_Banner->GetSizeInPixels().height());
    m_Banner->SetPosition(position);
    //m_Banner->AddTestDevice("514ED2E95AD8EECE454CC5565326160A");
    m_Banner->Show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent( QKeyEvent * event ){

    if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
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
    }
}
