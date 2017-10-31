#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->AboutButton,SIGNAL(clicked(bool)),this,SLOT(AboutSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AboutSlot()
{
    AboutWindow WindowBase;
    WindowBase.exec();
}
