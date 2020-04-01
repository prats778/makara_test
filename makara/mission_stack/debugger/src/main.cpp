#include "debugger/mainwindow.h"
#include "ros/ros.h"
#include <QApplication>

int main(int argc, char *argv[])
{   ros::init(argc, argv, "debugger");
    ros::NodeHandle nh;
    QApplication a(argc, argv);
    MainWindow w(nh);
    w.show();
    /*ros::Rate rate(0.5);
    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
        a.processEvents();
    }
    return 0;*/

    return a.exec();
}
