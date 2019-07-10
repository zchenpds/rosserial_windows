#ifndef _ROS_gait_training_robot_HumanSkeletonAzure_h
#define _ROS_gait_training_robot_HumanSkeletonAzure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"

namespace gait_training_robot
{

  class HumanSkeletonAzure : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _k4a_timestamp_usec_type;
      _k4a_timestamp_usec_type k4a_timestamp_usec;
      typedef uint32_t _id_type;
      _id_type id;
      geometry_msgs::Pose poses[26];
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

    HumanSkeletonAzure():
      header(),
      k4a_timestamp_usec(0),
      id(0),
      poses()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_k4a_timestamp_usec;
      u_k4a_timestamp_usec.real = this->k4a_timestamp_usec;
      *(outbuffer + offset + 0) = (u_k4a_timestamp_usec.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k4a_timestamp_usec.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_k4a_timestamp_usec.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_k4a_timestamp_usec.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->k4a_timestamp_usec);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      for( uint32_t i = 0; i < 26; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_k4a_timestamp_usec;
      u_k4a_timestamp_usec.base = 0;
      u_k4a_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k4a_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_k4a_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_k4a_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->k4a_timestamp_usec = u_k4a_timestamp_usec.real;
      offset += sizeof(this->k4a_timestamp_usec);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      for( uint32_t i = 0; i < 26; i++){
      offset += this->poses[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "gait_training_robot/HumanSkeletonAzure"; };
    const char * getMD5(){ return "00dd94bfdae56c9aae4ff6742aeeacd3"; };

  };

}
#endif