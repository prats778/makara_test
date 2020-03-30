#include<vectornav/vectornav.h>
#include<ros/ros.h>
#include <cstdlib>
#include<debugger/log_tools.h>
int rand();
int main(int argc,char** argv)
{  ros::init(argc,argv,"vectornav"); ////initializing ros node
   ros::NodeHandle n;
   ros::Publisher pub=n.advertise<vectornav::vectornav>("vectornav",1000);
   vectornav::vectornav msg;
   for(int i=0;i<3;i++)
       { msg.orientation[i]=(float)(rand()%10);
         msg.acceleration[i]=(float)(rand()%10);
        }
   pub.publish(msg);
   AUV_DEBUG("published vector nav message",2);
}

   
