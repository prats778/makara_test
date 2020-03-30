
#include <iostream>
#include <string>
#include <time.h>
#include <stdarg.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


template<typename First>
void AUV_DEBUG(std::string s,int key)
{    ros::NodeHandle n;
    
    if(key==1)//from synchronizer
    {ros::Publisher pub = n.advertise<std_msgs::String>("synchronizer_debugg", 1000);
     std_msgs::String msg;
     std::stringstream ss1;
     ss1<<s;
     msg.data=ss1.str();
     pub.publish(msg);
     loop_rate.sleep();
     
     ros::spinOnce();}
    if(key==2)//from vectornav
    {ros::Publisher pub = n.advertise<std_msgs::String>("vectornav_debugg", 1000);
     std_msgs::String msg;
     std::stringstream ss1;
     ss1<<s;
     msg.data=ss1.str();
     pub.publish(msg);
     loop_rate.sleep();
     
     ros::spinOnce();}
     if(key==3)//from serialnode
    {ros::Publisher pub = n.advertise<std_msgs::String>("serialnode_debugg", 1000);
     std_msgs::String msg;
     std::stringstream ss1;
     ss1<<s;
     msg.data=ss1.str();
     pub.publish(msg);
     loop_rate.sleep();
     
     ros::spinOnce();}
     
     
    
  /*  time_t timev;
    std::cout<<"[DEBUG] ["<<time(&timev)<<"]: "<<first<<" ";
    std::cout << std::endl;*/
}


