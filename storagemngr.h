#ifndef STORAGEMNGR_H
#define STORAGEMNGR_H

#include "mytypes.h"
#include "aktionmngr.h"

class StorageMngr
{
public:
    StorageMngr(QString filePath);
    ~StorageMngr();

    void reStoreAll( QList<AKTIONMNGR_DATA> dataList);
    //void remove( QString id );

    AKTIONMNGR_DATA getInitData( QString id );
    QString getInitDataString( QString id );

    QList<AKTIONMNGR_DATA> getInitDataList();
    QString getNewID();


    QString aktionMngrDataToQString(const AKTIONMNGR_DATA &data);
    AKTIONMNGR_DATA aktionMngrDataFromQString(QString str);
    AKTION getAktionByQString(QString str);

    QString filePath;

private:

    bool idExists( QString id );
    bool saveIntInVarFailed(int &saveTo, const QString &str);

    [[noreturn]] void fileOpenFailed();

};

#endif // STORAGEMNGR_H
