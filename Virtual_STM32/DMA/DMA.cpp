#include "DMA.h"
#include <memory>

#include "Timer.h"
#include "I2C.h"
#include "SPI.h"

DMA::DMA(const char* name) : Master(name), Slave(name)
{
    std::string reg_name(name);
    this->Name = name;
    DMA_Reg = std::make_unique<DMA_Resigter>((reg_name + "_register").c_str());
}

DMA::~DMA()
{
}

bool DMA::Transmit(Data_Package* package)
{
    uint32_t data = 0;
    memcpy((uint8_t*)&data,package->Buffer,package->Length);
    DMA_Reg->WriteResigter(package->Address,data);
    return true;
}

bool DMA::Received(Data_Package* package)
{
    uint32_t data = 0;
    data = DMA_Reg->ReadResigter(package->Address);
    memcpy(package->Buffer,(uint8_t*)&data,package->Length);
    return true;
}


