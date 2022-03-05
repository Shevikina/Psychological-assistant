#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    QFile file("komlpiment.txt"); // создаем объект класса QFile
    QString data; // Создаем объект класса QByteArray, куда мы будем считывать данные
    if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
    {
        qDebug() << "open error";
        return; // если это сделать невозможно, то завершаем функцию
    }
    data = file.readAll(); //считываем все данные с файла в объект data
    file.close();
    QStringList list1 = data.split('\n');

    ui->textEdit->setText(list1[QRandomGenerator::global()->bounded(0, list1.length())]);
}

