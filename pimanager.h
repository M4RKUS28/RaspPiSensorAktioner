#ifndef PIMANAGER_H
#define PIMANAGER_H

#include <QObject>
#include <QThread>
#include <string>
#include "my_tcp_lib.h"


class PiManager : public QThread
{
    Q_OBJECT
public:
    enum SENSOR {
        DOR_STATE,
        TEMPERATURE
    };

    PiManager();//(std::string ip, unsigned short port);
     ~PiManager();

    int connect(std::string ip, int port);
    void disconnect();
    bool isConnected();

    int getSensorState(enum SENSOR s);

    QString getLastErrorMsg();
private:
    client_TCP_Lib * client;
    //std::string ip;
    //unsigned short port;

    int dorState = 0;
    int temperature = 0;

    int startThread();
    int stopThread();

    int closeSocket();

    virtual void run();

signals:
    void connectionStatusChanged(int status);


};

#endif // PIMANAGER_H
