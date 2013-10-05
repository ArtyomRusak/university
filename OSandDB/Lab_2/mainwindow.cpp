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

void MainWindow::on__createHeap_clicked()
{
    heap = new MemHeaper();

    EnableCreation(true);
}

void MainWindow::on__deleteHeap_clicked()
{
    delete heap;

    EnableCreation(false);
}

void MainWindow::on__taskDefault_clicked()
{
    std::stringstream stream;
    ui->_informationEdit->append(ALLOC_MEMORY);

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

    stream << "First members of region: ";
    for(int i = 0; i < 10; i++)
    {
        stream << firstRegion[i] << " ";
    }
    stream << std::endl;
    ui->_informationEdit->append(QString(stream.str().c_str()));

    heap->MemFree(firstRegion);
    heap->MemFree(secondRegion);

    ui->_informationEdit->append(MEMORY_CLEAR_TEXT);
}

void MainWindow::EnableCreation(BOOL check)
{
    ui->_allocMemory->setEnabled(check);
    ui->_clearMemory->setEnabled(check);
    ui->_deleteHeap->setEnabled(check);
    ui->_taskDefault->setEnabled(check);
    ui->_sizeEdit->setEnabled(check);
    ui->_createHeap->setEnabled(!check);
}

void MainWindow::on__allocMemory_clicked()
{
    int size = ui->_sizeEdit->toPlainText().toInt();
    if(size != 0)
    {
        dataForTask = (int*)heap->MemAlloc(size);
        //FillMemory(dataForTask, size, 0x7B);
        for(int i = 0; i < size; i++)
        {
            dataForTask[i] = 0x7B;
        }

        std::stringstream stream;
        stream << "Elements in allocated memory : ";
        for(int i = 0; i < size; i++)
        {
            stream << dataForTask[i] << " ";
            //ui->_informationEdit->append(QString::number(dataForTask[i]));
        }
        stream << std::endl;

        ui->_informationEdit->append(QString(stream.str().c_str()));
        stream.clear();
    }
    else
    {
        QMessageBox::information(this, WARNING, ERROR_NUMBERS, QMessageBox::Ok);
    }
}

void MainWindow::on__clearMemory_clicked()
{
    if(HeapValidate(heap->GetHeap(), HEAP_NO_SERIALIZE, dataForTask))
    {
        heap->MemFree(dataForTask);
        ui->_informationEdit->append(MEMORY_CLEAR_TEXT);
    }
    else
    {
        QMessageBox::information(this, WARNING, ERROR_ALLOC_MEMORY, QMessageBox::Ok);
    }
}
