
#include <iostream>
#include <string>
#include <time.h>
#include <stdarg.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


//template<typename First>
void AUV_DEBUG(std::string s,int key)
{    ros::NodeHandle n;
    
    if(key==1)//from synchronizer
    {ros::Publisher pub = n.advertise<std_msgs::String>("synchronizer_debugg", 1000);
     std_msgs::String msg;
     std::stringstream ss1;
     ss1<<s;
     msg.data=ss1.str();
     ros::Rate loop_rate(0.5);
     int i=0;
    while(i<2)//message has to be published atleast 2 times for subs in debugger to pick up messge
     {pub.publish(msg);
     ros::spinOnce();
     loop_rate.sleep();
     ROS_INFO("auv debug synchronizer has published\n"); 
     ROS_INFO("debug mssge IS[%s]",msg.data.c_str());
     i++;
     }
    } //ros::Rate loop_rate.sleep();
     
     //ros::spinOnce();}
    if(key==2)//from vectornav
    {ros::Publisher pub = n.advertise<std_msgs::String>("vectornav_debugg", 1000);
     std_msgs::String msg;
     std::stringstream ss1;
     ss1<<s;
     msg.data=ss1.str();
     ros::Rate loop_rate(0.5);
     int i=0;
    while(i<2)//message has to be published atleast 2 times for subs in debugger to pick up messge
     {pub.publish(msg);
     ros::spinOnce();
     loop_rate.sleep();
     ROS_INFO("auv debug vectornav has published\n"); 
     ROS_INFO("debug mssge IS[%s]",msg.data.c_str());
     i++;
     }
    }
     //ros::Rate loop_rate.sleep();
     
     //ros::spinOnce();}
     if(key==3)//from serialnode
    {ros::Publisher pub = n.advertise<std_msgs::String>("serialnode_debugg", 1000);
     std_msgs::String msg;
     std::stringstream ss1;
     ss1<<s;
     msg.data=ss1.str();
     ros::Rate loop_rate(0.5);
      int i=0;
    while(i<2)//message has to be published atleast 2 times for subs in debugger to pick up messge
     {pub.publish(msg);
     ros::spinOnce();
     loop_rate.sleep();
     ROS_INFO("auv debug serialnode has published\n"); 
     ROS_INFO("debug mssge IS[%s]",msg.data.c_str());
     i++;
     }
    }
     //ros::Rate loop_rate.sleep();
     
     //ros::spinOnce();}
     
     
    
  /*  time_t timev;
    std::cout<<"[DEBUG] ["<<time(&timev)<<"]: "<<first<<" ";
    std::cout << std::endl;*/
}


