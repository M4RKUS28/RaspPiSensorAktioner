#include "pimanager.h"

PiManager::PiManager()//std::string ip, unsigned short port)
 //   : ip(ip), port(port), dorState( -1 )
{
    client = new client_TCP_Lib();
    client->autoCleanUpInTheEnd = false;

}

PiManager::~PiManager()
{
    perror("~PiMNGER");
    if(client->isConnected()) {
        disconnect();
    }

    if( stopThread() != 0 )
        return; // not delete vars used in thread

    delete client;
}


#include <iostream>


void PiManager::run()
{
// überwarbeitbar!!!!!

    perror("Thread");
    while ( !isInterruptionRequested() ) {
        int ret_;
        if( (ret_ = send(client->getConnectionSocket(), "pw", 2, 0) ) == 0) {
            perror("connection shutdownd");
            emit connectionStatusChanged(0);
dorState = -1;

            return;
        } else if ( ret_ < 0) {
            perror("recv failed");
            emit connectionStatusChanged(0);
dorState = -1;

            return;
        }

        char c;
        int ret;

        if( (ret = recv(client->getConnectionSocket(), &c, 1, 0) ) == 0) {
            perror("connection shutdownd");
            emit connectionStatusChanged(0);
dorState = -1;

            return;
        } else if ( ret < 0) {
            perror("recv failed");
            emit connectionStatusChanged(0);

dorState = -1;
            return;
        }
//HIER!!!!!!
        bool ok;
        int ds = QString(c).toInt( &ok );
        if( ok )
            dorState = ds;

    }

    perror("thread exit");


}




int PiManager::connect(std::string ip, int port)
{
    if( client->isConnected() )
        return 1;
    if(client->connectTo(client->getIpByName(ip), port) != 0) {
        std::cerr << ("connect failed") << client->getLastError() << std::endl;
        return 2;
    }
    emit connectionStatusChanged(1);

    if( startThread() != 0) {
        perror("start thread failed");
        closeSocket();

    }

    return 0;
}

void PiManager::disconnect()
{
    if( !isConnected() ) {
        return;
    }
    if( stopThread() != 0) {
        perror(":  stopThread failed ");
    }

    if( closeSocket() != 0) {
        perror(":  stopThread failed ");

    }

    emit connectionStatusChanged(0);


}

bool PiManager::isConnected()
{
    return client->isConnected();
}

int PiManager::getSensorState(PiManager::SENSOR s)
{
    if(s == SENSOR::DOR_STATE) {
        return dorState;

    } else if( s == SENSOR::TEMPERATURE) {
        return temperature;
    }
    return 0;
}

QString PiManager::getLastErrorMsg()
{
    return QString::fromStdString( client->getLastError() );
}

int PiManager::startThread()
{
    if(this->isRunning()) {
        perror("thrwad already running");
        return 1;
    }

    this->start();
    return 0;
}

int PiManager::stopThread()
{
    if(this->isRunning()) {
        this->quit();
        if( this->wait(100) == false ) {
            this->terminate();
            if( this->wait(300) == false ) {
                perror("stop threwadf failed!!");
                return -1;
            }
        }
    }
    return 0;
}

int PiManager::closeSocket()
{
    if( ! client->isConnected() )
        return 0;

    int i;
    if( (i = client->closeSocket()) != 0) {
        perror("closescoket failed");
        emit connectionStatusChanged(4);

    } else {
        perror("scoket closed succesful");
        emit connectionStatusChanged(3);

    }
    return i;
}

