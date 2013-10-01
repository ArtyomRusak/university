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

void MainWindow::on_pb_start_clicked()
{

    // -------------------------------------------------------------------------------------
    // Здесь запрограммировать действия с памятью, соответствующие индивидуальному заданию
    // -------------------------------------------------------------------------------------


    MemHeaper my_heap; // Создание экземпляра класса MemHeaper (создание кучи производится в конструкторе)
    int* a = (int*)my_heap.MemAlloc(10*sizeof(int)); // Выделение блока памяти в куче

    a[5] = 42; // пятому элементу типа int из выделенного блока присваивается значение 42


    // Вывод в textEdit
    ui->textEdit->append("Первое значение из выделенного региона памяти: " + QString::number(a[0]));
    ui->textEdit->append("Пятое значение из выделенного региона памяти: " + QString::number(a[5]));


    my_heap.MemFree((void*)a); // Освобождение блока памяти в куче

}
