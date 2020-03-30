#include "debugger/mainwindow.h"
#include "debugger/log_tools.h"
#include "ui_mainwindow.h"
#include "ros/ros.h"
#include <string>


ros::NodeHandle n;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->channel, SIGNAL(currentIndexChanged(int)),this,SLOT(inp(int)));
    connect(ui->clear, SIGNAL(pressed()),this,SLOT(clear());
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Mainwindow::inp(int val)
{if(val==0)
    ros::Subscriber sub = n.subscribe("synchronizer_debugg", 1000, callback);
 if(val==1)
    ros::Subscriber sub = n.subscribe("vectornav_debugg",1000,callback);
 if(val==2)
    ros::Subscriber sub = n.subscribe("serialnode_debugg",1000,callback);
   
}
void Mainwindow::callback(const std_msgs::String msg)
{   QString str = QString::fromUtf8(msg.data.c_str());
    ui->display->setText(str);
}
void Mainwindow::clear()
{   ui->display->setText("");
}
