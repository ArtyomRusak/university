#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "memheaper.h"
#include <Windows.h>

const int sizeOfRegion = 8192;
const char ERROR_TEXT[] = "Error";
const char ERROR_CREATE_TEXT[] = "Create a heap before allocaring memory.";

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
    void createButton_clicked();

    void on__createHeap_clicked();

    void on__deleteHeap_clicked();

    void on__taskDefault_clicked();

private:
    Ui::MainWindow *ui;
    int *firstRegion;
    int *secondRegion;
    int *dataForTask;
    MemHeaper *heap;
};

#endif // MAINWINDOW_H
