#include "Register.h"

Bit_Config::Bit_Config ()
{
    this->Bit_Name   = "";
    this->Start_Addr = 0;
    this->End_Addr   = 0;
    this->Permit     = e_Permit::ReadWrite;
    this->Init_Val   = 0;
    this->Data       = 0;
}

Bit_Config::Bit_Config (const char* _name, uint32_t start_addr, uint32_t end_addr,
                        e_Permit _permit,uint32_t init, uint32_t data)
{
    this->Bit_Name   = _name;
    this->Start_Addr = start_addr;
    this->End_Addr   = end_addr;
    this->Permit     = _permit;
    this->Init_Val   = init;
    this->Data       = data;
}

Bit_Config& Bit_Config::operator = (unsigned int val)
{
     uint32_t mask = (uint32_t)((1 << (this->End_Addr - this->Start_Addr + 1)) - 1);
     
}