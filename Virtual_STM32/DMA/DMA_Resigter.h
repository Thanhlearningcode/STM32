#pragma once

#include "Register.h"
#include <map>
#include <memory>
class DMA;
class DMA_Resigter
{
friend class DMA;
private:
    const char* Name;
    std::map<uint32_t, std::unique_ptr<Resigter>> RegMap;
    Resigter* DMA_CCR;
    Resigter* DMA_CMAR;
    Resigter* DMA_CPAR;
    Resigter* DMA_CNDTR;

    DMA_Resigter (const char* name);
    ~DMA_Resigter();

    uint32_t ReadResigter  (uint32_t offset);
    void     WriteResigter (uint32_t offset, uint32_t value);
};