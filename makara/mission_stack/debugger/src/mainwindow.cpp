#include "debugger/mainwindow.h"
#include "debugger/log_tools.h"
#include "ui_mainwindow.h"
#include "ros/ros.h"
#include <string>

QString str,str2,str_syn,str_vector,str_serial;
//ros::init(int argc,char** argv);
//ros::NodeHandle n;
int ch=2;
//int flag=1;



MainWindow::MainWindow(ros::NodeHandle _nh,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),n(_nh)
{
    ui->setupUi(this);
    connect(ui->channel, SIGNAL(currentIndexChanged(int)),this,SLOT(inp(int)));
    connect(ui->clear, SIGNAL(pressed()),this,SLOT(clear()));
    ROS_INFO("SLOTS CONNECTED");
    ros::Rate rate(0.5);
    sub_synchronizer = n.subscribe("synchronizer_debugg", 1000,&MainWindow::callback1,this);
    ROS_INFO("received synchro auv statement\n");
    
   
    sub_vectornav= n.subscribe("vectornav_debugg",1000,&MainWindow::callback2,this);
    ROS_INFO("received vectornav auv statement\n");
    
    
   
    sub_serialnode = n.subscribe("serialnode_debugg",1000,&MainWindow::callback3,this);
    ROS_INFO("received serialnode auv statement\n");
   while (n.ok()){
    ros::spinOnce(); // this is where the magic happens!!
    rate.sleep();
  }


 }
    
MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::inp(int val)
  {
   ch=val;
   ROS_INFO(" ch is [%d]",ch);
  }
void MainWindow::clear()
{  int data=3; 
   ch=10;//ASSIGNING A ARBITRARY VALUE SO THAT NOTHING IS DISPLAYED
   ROS_INFO("OK");
   ui->display->setText("hey there");
   

}
void MainWindow::callback1(const std_msgs::String::ConstPtr& msg)
{   ROS_INFO("WE R IN CALLBACK FUNC 1\n");
    str_syn = QString::fromUtf8(msg->data.c_str());
    
    ROS_INFO("[%s]",msg->data.c_str());
  if(ch==0)   
    ui->display->setText(str_syn);
}
void MainWindow::callback2(const std_msgs::String::ConstPtr& msg)
{   ROS_INFO("WE R IN CALLBACK FUNC 2\n");
    str_vector = QString::fromUtf8(msg->data.c_str());
    
    ROS_INFO("[%s]",msg->data.c_str());   
   if(ch==1)
         ui->display->setText(str_vector);
}
void MainWindow::callback3(const std_msgs::String::ConstPtr& msg)
{   ROS_INFO("WE R IN CALLBACK FUNC 3\n");
    str_serial = QString::fromUtf8(msg->data.c_str());
    
    ROS_INFO("[%s]",msg->data.c_str());   
   if(ch==2)
         ui->display->setText(str_serial);
}

