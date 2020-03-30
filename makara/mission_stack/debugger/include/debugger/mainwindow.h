#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QTimer>
#include <QString>
#include "ros/ros.h"
#include "std_msgs/String.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
     void input(int); 
     void callback(const std_msgs::String msg);  
     void clear();   

private:
    Ui::MainWindow *ui;
    std::string topic;
};

#endif // MAINWINDOW_H
