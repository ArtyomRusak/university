#include "memheaper.h"

MemHeaper::MemHeaper() // Конструктор MemHeaper
{

    heap = HeapCreate(HEAP_NO_SERIALIZE | HEAP_GROWABLE, 0, 0); // Создание кучи

    // Добавить проверку на возможные ошибки !!!
    // ...

}

void* MemHeaper::MemAlloc(int size)
{
    // Выделение блока памяти
    return (void*)HeapAlloc(heap, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, size);

    // Добавить проверку на возможные ошибки !!!
    // ...



}

void MemHeaper::MemFree(void* addr)
{
    HeapFree(heap, HEAP_NO_SERIALIZE, (LPVOID) addr);

    // Добавить проверку на возможные ошибки !!!
    // ...


}

void MemHeaper::MemInfo()
{

    // Здесь необходимо использовать функцию HeapWalk для получение информации о блоках памяти в куче
    // ...

    // HeapWalk(...)

    // Добавить проверку на возможные ошибки !!!
    // ...

    return;
}
