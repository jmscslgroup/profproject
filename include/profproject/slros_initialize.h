#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "profproject_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block profproject/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_profproject_std_msgs_Float64> Sub_profproject_39;

// For Block profproject/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_profproject_std_msgs_Float64> Pub_profproject_35;

void slros_node_init(int argc, char** argv);

#endif
