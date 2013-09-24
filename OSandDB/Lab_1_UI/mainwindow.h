#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <windows.h>

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
const char BASE_ADDRESS_FIRST[] = "Base address of first region : ";
const int sizeOfRegion = 8192;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    BYTE* firstRegion;
    BYTE* secondRegion;


private slots:
    void GetInformationAboutSystem();
    int AllocMemory();
    int FreeMemory();
};

#endif // MAINWINDOW_H
