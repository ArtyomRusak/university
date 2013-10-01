#ifndef MEMHEAPER_H
#define MEMHEAPER_H

#include "windows.h"

class MemHeaper
{
public:
    MemHeaper();
    void* MemAlloc(int size);
    void MemFree(void* addr);
    void MemInfo();

private:
    HANDLE heap;

};

#endif // MEMHEAPER_H
