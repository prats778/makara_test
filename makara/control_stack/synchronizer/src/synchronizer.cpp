#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <serialnode/depth.h>
#include <vectornav/vectornav.h>
#include <synchronizer/syncdata.h>
#include <debugger/log_tools.h>

using namespace message_filters;

ros::Publisher pub;

void callback(const serialnode::depth::ConstPtr& depthMsg, const vectornav::vectornav::ConstPtr& imuMsg)
{
    synchronizer::syncdata msg;

    msg.angular = imuMsg->orientation;
    msg.linear = imuMsg->acceleration;
    msg.depth = depthMsg->depth;

    pub.publish(msg);

    AUV_DEBUG("published message on synchronizer",1);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "synchronizer");

    ros::NodeHandle nh;
    pub = nh.advertise<synchronizer::syncdata>("synchronizer",1000);
    message_filters::Subscriber<serialnode::depth> depthSub(nh, "serialnode", 1000);
    message_filters::Subscriber<vectornav::vectornav> imuSub(nh, "vectornav", 1000);
    typedef sync_policies::ApproximateTime<serialnode::depth, vectornav::vectornav> MySyncPolicy;
    Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), depthSub, imuSub);
    sync.registerCallback(boost::bind(&callback, _1, _2));

    ros::spin();

    return 0;
}
