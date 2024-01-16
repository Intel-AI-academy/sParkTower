#include "parkingdb.h"

ParkingDB::ParkingDB()
{
    p_SocketClient = new SocketClient;
    p_ManagerModeUI = new ManagerModeUI;


    connect(p_SocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(RecvUpdateSlot(QString)));
    //connect(this, SIGNAL(x_sig(QString)), p_ManagerModeUI, SLOT(soket_data(QString)));
    //connect(this, SIGNAL(time_sig(QString)), this, SLOT(RecvUpdateSlot(QString)));

}

ParkingDB::~ParkingDB(){

}
