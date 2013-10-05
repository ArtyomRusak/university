#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "memheaper.h"
#include <Windows.h>
#include <sstream>

const int sizeOfRegion = 8192;
const char ERROR_TEXT[] = "Error";
const char ERROR_CREATE_TEXT[] = "Create a heap before allocating memory.";
const char WARNING[] = "Warning";
const char ERROR_NUMBERS[] = "A value must be greater than 0, or you enter char symbols!";
const char ERROR_ALLOC_MEMORY[] = "You must alloc memory!";
const char MEMORY_CLEAR_TEXT[] = "Memory was cleared!";
const char ALLOC_MEMORY[] = "Allocated memory for 2 regions.";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on__createHeap_clicked();

    void on__deleteHeap_clicked();

    void on__taskDefault_clicked();

    void on__allocMemory_clicked();

    void on__clearMemory_clicked();

private:
    Ui::MainWindow *ui;
    int *firstRegion;
    int *secondRegion;
    int *dataForTask;
    MemHeaper *heap;

    void EnableCreation(BOOL);
};

#endif // MAINWINDOW_H
