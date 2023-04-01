#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    int msec,sec,min;
    QTimer *timer;
    bool *flag;
private slots:
void timerSlot();


void on_pushButton_clicked();
void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
