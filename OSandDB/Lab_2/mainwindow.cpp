#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "memheaper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createButton_clicked()
{

    // -------------------------------------------------------------------------------------
    // Здесь запрограммировать действия с памятью, соответствующие индивидуальному заданию
    // -------------------------------------------------------------------------------------


    MemHeaper my_heap; // Создание экземпляра класса MemHeaper (создание кучи производится в конструкторе)
    int* a = (int*)my_heap.MemAlloc(10*sizeof(int)); // Выделение блока памяти в куче

    a[5] = 42; // пятому элементу типа int из выделенного блока присваивается значение 42


    // Вывод в textEdit
    ui->_informationEdit->append("Первое значение из выделенного региона памяти: " + QString::number(a[0]));
    ui->_informationEdit->append("Пятое значение из выделенного региона памяти: " + QString::number(a[5]));


    my_heap.MemFree((void*)a); // Освобождение блока памяти в куче

}

void MainWindow::on__createHeap_clicked()
{
    heap = new MemHeaper();
}

void MainWindow::on__deleteHeap_clicked()
{
    delete heap;
}

void MainWindow::on__taskDefault_clicked()
{
    if (heap)
    {
        ui->_informationEdit->append("Allocated memory for 2 regions.");

        firstRegion = (int*)heap->MemAlloc(sizeOfRegion);
        if(!firstRegion)
        {
            return;
        }

        secondRegion = (int*)heap->MemAlloc(sizeOfRegion);
        if(!secondRegion)
        {
            return;
        }

        FillMemory(firstRegion, sizeOfRegion, 0x0F);
        CopyMemory(secondRegion, firstRegion, sizeOfRegion);

        QString informationAboutRegion;
        informationAboutRegion + "First members of region: ";
        for(int i = 0; i < 10; i++)
        {
            informationAboutRegion + firstRegion[i] + " ";
        }
        ui->_informationEdit->append("");

        heap->MemFree(firstRegion);
        heap->MemFree(secondRegion);

        ui->_informationEdit->append("Memory was cleared.");
    }
    else
    {
        QMessageBox::information(this, ERROR_TEXT, ERROR_CREATE_TEXT, QMessageBox::Ok);
    }
}
