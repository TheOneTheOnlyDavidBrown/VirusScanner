#include "scannerthread.h"
#include <QtCore>

scannerThread::scannerThread(QObject *parent) :
    QThread(parent)
{
}

void scannerThread::run()
{
    this->Stop=false;
    QMutex mutex;
    QFile fin( "virussigdatabase" );
    if (!fin.open(QIODevice::ReadOnly))
    {
        this->Stop=true;
    }
    //int i,j,k;
    //k=0;
    //int minMatches;
    //int virusMatchTotal=0;
    //int consecutiveCount;

    while(!this->Stop)
    {
        this->virusName = fin.readLine();
        QByteArray virusSignature = fin.readLine();

        //int numberOfMatches=0;
        //int virusMatch=0;
        //int fileSignatureLength = this->fileSignature.length();
        //int virusSignatureLength=virusSignature.length() ;
        //int virusIndex;
        //int numOddballs=0;

        //exact match search
        if(fileSignature.contains(virusSignature))
        {
            this->Stop=true;
            emit outputResult();
        }
        //end exact match search



        mutex.lock();
        if (this->Stop)
        {
            break;
        }
        mutex.unlock();

    }
}
