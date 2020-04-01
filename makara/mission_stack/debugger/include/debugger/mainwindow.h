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
      explicit MainWindow(ros::NodeHandle _nh,QWidget *parent = 0);
    ~MainWindow();
     
     void callback1(const std_msgs::String::ConstPtr& msg); 
     void callback2(const std_msgs::String::ConstPtr& msg); 
     void callback3(const std_msgs::String::ConstPtr& msg); 
    
public slots:
     void inp(int ); 
     //static void callback(const std_msgs::String msg);  
     void clear();   

private:
    Ui::MainWindow *ui;
    std::string topic;
    ros::NodeHandle n;
    ros::Subscriber sub_synchronizer;
    ros::Subscriber sub_vectornav;
    ros::Subscriber sub_serialnode;
};

#endif // MAINWINDOW_H
