#include "memheaper.h"

MemHeaper::MemHeaper() // Конструктор MemHeaper
{
    heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_GROWABLE, sizeOfHeap, 0);
}

MemHeaper::~MemHeaper()
{
    HeapDestroy(heap);
}

void* MemHeaper::MemAlloc(int size)
{
    LPVOID _heap;
    _heap = HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, size * sizeof(int));

    if(!_heap)
    {
        MemHeaper::getError();
        return NULL;
    }
    else
    {
        return _heap;
    }
}

void MemHeaper::MemFree(void* address)
{
    if(!HeapFree(heap, HEAP_NO_SERIALIZE, (LPVOID) address))
    {
        MemHeaper::getError();
    }
}

void MemHeaper::MemInfo()
{



    return;
}

void MemHeaper::getError()
{
    LPTSTR errorText = NULL;
    FormatMessage(
       FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
       NULL,
       GetLastError(),
       MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
       (LPTSTR)&errorText,
       0,
       NULL);

    QString errorMessage = QString::fromWCharArray(errorText);

    QMessageBox messageBox;
    messageBox.setWindowTitle("Error");
    messageBox.setText(errorMessage);
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.exec();
}
