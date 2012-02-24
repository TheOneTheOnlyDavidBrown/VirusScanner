#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnStopScan->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QByteArray MainWindow::getHexFootprint()
{
    QFile fin(QFileDialog::getOpenFileName(this, tr("Open File To Scan"),"",tr("Files (*.*)")));
    if (!fin.open(QIODevice::ReadOnly))
    {
        ui->listResults->addItem("file did not open");
    }

    QByteArray ba;
    ba = fin.readAll();

    fin.close();
    return ba.toHex();
}

void MainWindow::on_btnOpenFile_clicked()
{

}

void MainWindow::onOutputResults()
{
    ui->listResults->addItem(ScannerThread->virusName);
    ui->listResults->addItem("virus found");
    ui->btnStopScan->setVisible(false);
    ui->btnScan->setVisible(true);
}

void MainWindow::on_btnStopScan_clicked()
{
    ui->btnStopScan->setVisible(false);
    ui->btnScan->setVisible(true);
    //thread->stop=true;
}

void MainWindow::on_btnScan_clicked()
{
    ui->btnScan->setVisible(false);
    ui->btnStopScan->setVisible(true);

    ScannerThread = new scannerThread(this);
    connect(ScannerThread,SIGNAL(outputResult()),this,SLOT(onOutputResults()));

    ScannerThread->fileSignature = getHexFootprint();

    ScannerThread->start();
}

void MainWindow::on_btnClearResults_clicked()
{
    ui->listResults->clear();
}
