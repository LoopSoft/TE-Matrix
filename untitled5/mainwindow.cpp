#include "mainwindow.h"
#include "ui_mainwindow.h"


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
