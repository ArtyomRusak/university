#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->_informationButton, SIGNAL(clicked()), this, SLOT(GetInformationAboutSystem()));
    connect(ui->_memoryButton, SIGNAL(clicked()), this, SLOT(FreeMemory()));
    connect(ui->_memoryButton, SIGNAL(pressed()), this, SLOT(AllocMemory()));

    //QMessageBox("Box", "Hello", QIcon.Active, 0, 0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetInformationAboutSystem()
{
    //QMessageBox("Box", "Hello", QIcon.Active, 0, 0, 0);
    ui->_informationEdit->clear();
    SYSTEM_INFO info;
    MEMORYSTATUS memory;
    GetSystemInfo(&info);
    GlobalMemoryStatus(&memory);
    ui->_informationEdit->append(SIZE_OF_PAGE + QString::number((DWORD)info.dwPageSize));
    ui->_informationEdit->append(MINIMUM_APPLICATION_ADDRESS + QString::number((DWORD)info.lpMinimumApplicationAddress));
    ui->_informationEdit->append(MAXIMUM_APPLICATION_ADDRESS + QString::number((DWORD)info.lpMaximumApplicationAddress));
    ui->_informationEdit->append(ALLOCATION_GRANULARITY + QString::number((DWORD)info.dwAllocationGranularity));
    ui->_informationEdit->append(NUMBER_OF_PROCESSORS + QString::number((DWORD)info.dwNumberOfProcessors));
    ui->_informationEdit->append(ACTIVE_PROCESSORS_MASK + QString::number((DWORD)info.dwActiveProcessorMask));
    ui->_informationEdit->append(PROCESSOR_TYPE + QString::number((DWORD)info.dwProcessorType));
    ui->_informationEdit->append(AVAILABLE_MEMORY + QString::number((DWORD)memory.dwAvailPhys));
}

int MainWindow::AllocMemory()
{
    ui->_memoryEdit->clear();

    MEMORY_BASIC_INFORMATION info;

    if(firstRegion = (BYTE*)VirtualAlloc(NULL, sizeOfRegion, MEM_COMMIT, PAGE_READWRITE))
    {
        ui->_memoryEdit->append(MEMORY_RIGHT);
    }
    else
    {
        ui->_memoryEdit->append(MEMORY_ERROR);
        return GetLastError();
    }

    if(secondRegion = (BYTE*)VirtualAlloc(NULL, sizeOfRegion, MEM_COMMIT, PAGE_READWRITE))
    {
        ui->_memoryEdit->append(MEMORY_RIGHT);
    }
    else
    {
        ui->_memoryEdit->append(MEMORY_ERROR);
        return GetLastError();
    }


    FillMemory(firstRegion, sizeOfRegion, 0x0F);

    QString result;
    for(int i = 0; i < 10; i++)
    {
        result.append(QString::number((BYTE)firstRegion[i]) + " ");
    }
    ui->_memoryEdit->append(result);

    VirtualQuery(firstRegion, &info, sizeof(info));
    ui->_memoryEdit->append(REGION_SIZE + QString::number((DWORD)info.RegionSize));

    CopyMemory(secondRegion, firstRegion, sizeOfRegion);

    ui->_memoryEdit->append(BASE_ADDRESS_FIRST + QString::number((DWORD)info.BaseAddress, 16));

    return 0;
}

int MainWindow::FreeMemory()
{
    if(VirtualFree(firstRegion, sizeOfRegion, MEM_DECOMMIT))
    {
        ui->_memoryEdit->append(MEMORY_FREE_RIGHT);
    }
    else
    {
        ui->_memoryEdit->append(MEMORY_FREE_ERROR);
        return GetLastError();
    }

    if(VirtualFree(secondRegion, sizeOfRegion, MEM_DECOMMIT))
    {
        ui->_memoryEdit->append(MEMORY_FREE_RIGHT);
    }
    else
    {
        ui->_memoryEdit->append(MEMORY_FREE_ERROR);
        return GetLastError();
    }

    return 0;
}
