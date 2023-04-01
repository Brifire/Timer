#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    flag=new bool;
    msec=0;
    sec=0;
    min=0;
    ui->setupUi(this);
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::timerSlot);
    timer->start(1);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete flag;
}


void MainWindow::timerSlot()
{
msec++;
if(msec>=1000)
{
    msec=0;
    sec++;
}
if(sec>=60)
{
    sec=0;
    min++;
}

ui->label_3->setText(QString::number(msec));
ui->label_2->setText(QString::number(sec));
ui->label->setText(QString::number(min));
}

void MainWindow::on_pushButton_clicked()
{
  if(*flag==false)
  {
      ui->pushButton->setText("Start");
      *flag=true;
      timer->stop();
      return;
  }
   if(*flag==true)
  {
      ui->pushButton->setText("Stop");
      *flag=false;
      timer->start(1);
      return;
  }
}


void MainWindow::on_pushButton_2_clicked()
{
    msec=0;
    sec=0;
    min=0;
    ui->label_3->setText(QString::number(msec));
    ui->label_2->setText(QString::number(sec));
    ui->label->setText(QString::number(min));

}

