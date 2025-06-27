#pragma once 

#include "DMA_Resigter.h"
#include "BusInterface.h"
#include "Port.h"

class DMA : public Master , public Slave 
{
private:
    std::unique_ptr<DMA_Resigter> DMA_Reg; 
    const char*                   Name;
public:
    Port<unsigned int>            Clock_Port;
    Port<bool>                    Reset_Port;
public:
    DMA (const char* name);
    ~DMA();

/*Overriding function from slave class*/
    bool Transmit(Data_Package* package);
    bool Received(Data_Package* package);
};