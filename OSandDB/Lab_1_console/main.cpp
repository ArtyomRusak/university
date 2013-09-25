#include <QCoreApplication>
#include <windows.h>
#include <iostream>

using namespace std;

const char MEMORY_RIGHT[] = "Memory was commited.";
const char MEMORY_ERROR[] = "Commited of memory takes an error.";
const char MEMORY_FREE_RIGHT[] = "Memory was decommited(free).";
const char MEMORY_FREE_ERROR[] = "While decommited memory get an error";
const char SIZE_OF_PAGE[] = "Size of page in memory : ";
const char MINIMUM_APPLICATION_ADDRESS[] = "Minimum application address : ";
const char MAXIMUM_APPLICATION_ADDRESS[] = "Maximum application address : ";
const char ALLOCATION_GRANULARITY[] = "Allocation Granularity : ";
const char NUMBER_OF_PROCESSORS[] = "Number of processors : ";
const char ACTIVE_PROCESSORS_MASK[] = "Active processors mask : ";
const char PROCESSOR_TYPE[] = "Processor type : ";
const char REGION_SIZE[] = "Region size is : ";
const char AVAILABLE_MEMORY[] = "Available memory : ";
const char MEMBERS_OF_MEMORY[] = "First and last members of memory : ";

const int _length = 10;

void GetInformationAboutSystem(SYSTEM_INFO);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BYTE *firstRegion;
    BYTE *secondRegion;
    const int size = 8192;
    SYSTEM_INFO inf;
    MEMORY_BASIC_INFORMATION info;
    MEMORYSTATUS buffer;

    GetSystemInfo(&inf);
    GetInformationAboutSystem(inf);

    GlobalMemoryStatus(&buffer);
    cout << AVAILABLE_MEMORY << buffer.dwAvailPhys << endl;

    if(firstRegion = (BYTE*)VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE))
    {
        cout << MEMORY_RIGHT << endl;
    }
    else
    {
        cout << MEMORY_ERROR << endl;
        return GetLastError();
    }

    if(secondRegion = (BYTE*)VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE))
    {
        cout << MEMORY_RIGHT << endl;
    }
    else
    {
        cout << MEMORY_ERROR << endl;
        return GetLastError();
    }

    FillMemory(firstRegion, size, 0x0F);

    cout << MEMBERS_OF_MEMORY;
    for(int i = 0; i < _length; i++)
    {
        cout << hex << (int)firstRegion[i] << " ";
    }
    cout << endl;

    VirtualQuery(firstRegion, &info, sizeof(info));
    cout << REGION_SIZE << (double)info.RegionSize << endl;

    CopyMemory(secondRegion, firstRegion, size);

    if(VirtualFree(firstRegion, size, MEM_DECOMMIT))
    {
        cout << MEMORY_FREE_RIGHT << endl;
    }
    else
    {
        cout << MEMORY_FREE_ERROR << endl;
        return GetLastError();
    }

    if(VirtualFree(secondRegion, size, MEM_DECOMMIT))
    {
        cout << MEMORY_FREE_RIGHT << endl;
    }
    else
    {
        cout << MEMORY_FREE_ERROR << endl;
        return GetLastError();
    }
    
    return a.exec();
}

void GetInformationAboutSystem(SYSTEM_INFO info)
{
    cout << SIZE_OF_PAGE << info.dwPageSize << endl;
    cout << MINIMUM_APPLICATION_ADDRESS << info.lpMinimumApplicationAddress << endl;
    cout << MAXIMUM_APPLICATION_ADDRESS << info.lpMaximumApplicationAddress << endl;
    cout << ALLOCATION_GRANULARITY << info.dwAllocationGranularity << endl;
    cout << NUMBER_OF_PROCESSORS << info.dwNumberOfProcessors << endl;
    cout << ACTIVE_PROCESSORS_MASK << info.dwActiveProcessorMask << endl;
    cout << PROCESSOR_TYPE << info.dwProcessorType << endl;
}
