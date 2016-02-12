#include "splash.h"
#include "ui_splash.h"
#include <QQuickView>

Splash::Splash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Splash)
{
    ui->setupUi(this);
    QQuickView *view = new QQuickView();
    QWidget *container = QWidget::createWindowContainer(view, this);
    container->setMinimumSize(200, 200);
    //container->setMaximumSize(200, 200);
    container->setFocusPolicy(Qt::TabFocus);
    view->setSource(QUrl("SubWindow.qml"));
    ui->verticalLayout->addWidget(container);
}

Splash::~Splash()
{
    delete ui;
}
