#include<serialnode/depth.h>
#include<ros/ros.h>
#include <cstdlib>
#include<debugger/log_tools.h>
int rand();
int main(int argc,char** argv)
{  ros::init(argc,argv,"serialnode"); ////initializing ros node
   ros::NodeHandle n;
   ros::Publisher pub=n.advertise<serialnode::depth>("serialnode",1000);
   serialnode::depth msg;
   msg.depth=(float)(rand()%10);
   pub.publish(msg);
   AUV_DEBUG("published serialnode message",3);
}

   
