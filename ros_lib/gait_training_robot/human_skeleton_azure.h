#ifndef _ROS_gait_training_robot_human_skeleton_azure_h
#define _ROS_gait_training_robot_human_skeleton_azure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace gait_training_robot
{

  class human_skeleton_azure : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      enum { K4ABT_JOINT_PELVIS = 0 };
      enum { K4ABT_JOINT_SPINE_NAVAL = 1 };
      enum { K4ABT_JOINT_SPINE_CHEST = 2 };
      enum { K4ABT_JOINT_NECK = 3 };
      enum { K4ABT_JOINT_CLAVICLE_LEFT = 4 };
      enum { K4ABT_JOINT_SHOULDER_LEFT = 5 };
      enum { K4ABT_JOINT_ELBOW_LEFT = 6 };
      enum { K4ABT_JOINT_WRIST_LEFT = 7 };
      enum { K4ABT_JOINT_CLAVICLE_RIGHT = 8 };
      enum { K4ABT_JOINT_SHOULDER_RIGHT = 9 };
      enum { K4ABT_JOINT_ELBOW_RIGHT = 10 };
      enum { K4ABT_JOINT_WRIST_RIGHT = 11 };
      enum { K4ABT_JOINT_HIP_LEFT = 12 };
      enum { K4ABT_JOINT_KNEE_LEFT = 13 };
      enum { K4ABT_JOINT_ANKLE_LEFT = 14 };
      enum { K4ABT_JOINT_FOOT_LEFT = 15 };
      enum { K4ABT_JOINT_HIP_RIGHT = 16 };
      enum { K4ABT_JOINT_KNEE_RIGHT = 17 };
      enum { K4ABT_JOINT_ANKLE_RIGHT = 18 };
      enum { K4ABT_JOINT_FOOT_RIGHT = 19 };
      enum { K4ABT_JOINT_HEAD = 20 };
      enum { K4ABT_JOINT_NOSE = 21 };
      enum { K4ABT_JOINT_EYE_LEFT = 22 };
      enum { K4ABT_JOINT_EAR_LEFT = 23 };
      enum { K4ABT_JOINT_EYE_RIGHT = 24 };
      enum { K4ABT_JOINT_EAR_RIGHT = 25 };
      enum { K4ABT_JOINT_COUNT = 26 };

    human_skeleton_azure():
      header(),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "gait_training_robot/human_skeleton_azure"; };
    const char * getMD5(){ return "afd685bb64724ffaf11217cf63254396"; };

  };

}
#endif