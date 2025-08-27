#include "Uart.h"
#include <memory>


Uart::Uart(const char* name) : Master(name), Slave(name), baudrate(9600), busy(false), error(false), data_reg(0)
{
    this->Name = name;
}

Uart::~Uart() {}

void Uart::SetBaudrate(unsigned int br) {
    baudrate = br;
}

bool Uart::IsBusy() const {
    return busy;
}

bool Uart::HasError() const {
    return error;
}

void Uart::Reset() {
    busy = false;
    error = false;
    data_reg = 0;
}

void Uart::SetData(unsigned char d) {
    data_reg = d;
}

unsigned char Uart::GetData() const {
    return data_reg;
}

bool Uart::Transmit(Data_Package* package)
{
    if (busy) { error = true; return false; }
    busy = true;
    // Mô phỏng truyền dữ liệu UART
    if (package && package->Length > 0) {
        data_reg = package->Buffer[0];
    }
    busy = false;
    return true;
}

bool Uart::Received(Data_Package* package)
{
    if (busy) { error = true; return false; }
    busy = true;
    // Mô phỏng nhận dữ liệu UART
    if (package && package->Length > 0) {
        package->Buffer[0] = data_reg;
    }
    busy = false;
    return true;
}
