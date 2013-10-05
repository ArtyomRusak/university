#ifndef MEMHEAPER_H
#define MEMHEAPER_H

#include "windows.h"
#include <QMessageBox>

const int SIZE_OF_HEAP = 32768;

class MemHeaper
{
public:
    MemHeaper();
    ~MemHeaper();
    void* MemAlloc(int size);
    void MemFree(void* addr);
    HANDLE GetHeap();
    QHash<PVOID, DWORD> MemInfo(int count);

private:
    HANDLE heap;
    void getError();
};

#endif // MEMHEAPER_H
