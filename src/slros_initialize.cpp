#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "profproject";

// For Block profproject/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_profproject_std_msgs_Float64> Sub_profproject_39;

// For Block profproject/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_profproject_std_msgs_Float64> Pub_profproject_35;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

