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
        QMessageBox errorBox;
        errorBox.setText("Error open file.");
        errorBox.show();
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
    ui->textEdit->setText(complimentList[QRandomGenerator::global()->bounded(0, complimentList.length())]);
}

