#include<vectornav/data.h>
#include<ros/ros.h>
#include <cstdlib>
#include "/home/prats/catkin_ws/src/makara/mission_stack/debugger/include/debugger/log_tools.h"
int rand();
int main(int argc,char** argv)
{  ros::init(argc,argv,"vectornav"); ////initializing ros node
   ros::NodeHandle n;
   ros::Publisher pub=n.advertise<vectornav::data>("vectornav",1000);
   vectornav::data msg;
   
        msg.acceleration.push_back((float)(rand()%10));
        msg.acceleration.push_back((float)(rand()%10));
        msg.acceleration.push_back((float)(rand()%10));
        msg.orientation.push_back((float)(rand()%10));
        msg.orientation.push_back((float)(rand()%10));
        msg.orientation.push_back((float)(rand()%10));
   ROS_INFO("1-%f   2-%f  3-%f", msg.acceleration[0], msg.acceleration[1], msg.acceleration[2]);
         
         
         
        
   pub.publish(msg);
   AUV_DEBUG("published vector nav message\0",2);
   AUV_DEBUG("THIS IS ANOTHER VEC QUERY\0",2);
}

   
