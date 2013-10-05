#include "memheaper.h"

MemHeaper::MemHeaper()
{
    heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_GROWABLE, SIZE_OF_HEAP, 0);

    if(heap == NULL)
    {
        getError();
    }
}


MemHeaper::~MemHeaper()
{
    BOOL result = HeapDestroy(heap);

    if(result == FALSE)
    {
        getError();
    }
    else
    {
        heap = NULL;
    }
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
        getError();
    }
}


QHash<PVOID, DWORD> MemHeaper::MemInfo(int count)
{
    PROCESS_HEAP_ENTRY info;
    info.lpData = NULL;
    QHash<PVOID, DWORD> data;
    int i = 0;

    while (HeapWalk(heap, &info))
    {
        if(i == count || count > SIZE_OF_HEAP)
        {
            break;
        }

        data.insert(info.lpData, info.cbData);
    }

    return data;
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

HANDLE MemHeaper::GetHeap()
{
    return heap;
}
