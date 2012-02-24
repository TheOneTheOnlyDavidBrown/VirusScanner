#ifndef SCANNERTHREAD_H
#define SCANNERTHREAD_H

#include <QThread>

class scannerThread : public QThread
{
    Q_OBJECT
public:
    explicit scannerThread(QObject *parent = 0);
    void run();
    bool Stop;
    QString virusName;
    QByteArray fileSignature;

signals:
    void outputResult();

public slots:

};

#endif // SCANNERTHREAD_H
