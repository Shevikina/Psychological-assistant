#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file.setFileName("komlpiment.txt");
    if (!file.open(QIODevice::ReadOnly))
    {

        return;
    }
    compliment = file.readAll();
    file.close();
    complimentList = compliment.split('\n');

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    if(compliment.length()==0){
        QMessageBox errorBox;
        errorBox.setText("Error read date from file.");
        errorBox.exec();}
    else
        ui->textEdit->setText(complimentList[QRandomGenerator::global()->bounded(0, complimentList.length())]);
}

