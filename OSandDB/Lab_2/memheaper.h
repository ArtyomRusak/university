#ifndef MEMHEAPER_H
#define MEMHEAPER_H

#include "windows.h"
#include <QMessageBox>

const int sizeOfHeap = 32768;

class MemHeaper
{
public:
    MemHeaper();
    ~MemHeaper();
    void* MemAlloc(int size);
    void MemFree(void* addr);
    void MemInfo();

private:
    HANDLE heap;
    void getError();
};

#endif // MEMHEAPER_H
