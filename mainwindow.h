#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scannerthread.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QByteArray getHexFootprint();
    scannerThread *ScannerThread;

private slots:
    void on_btnOpenFile_clicked();
    void onOutputResults();
    void on_btnStopScan_clicked();

    void on_btnScan_clicked();

    void on_btnClearResults_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
