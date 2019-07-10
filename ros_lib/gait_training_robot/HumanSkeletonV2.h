#ifndef _ROS_gait_training_robot_HumanSkeletonV2_h
#define _ROS_gait_training_robot_HumanSkeletonV2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace gait_training_robot
{

  class HumanSkeletonV2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t point_length;
      typedef geometry_msgs::Point _point_type;
      _point_type st_point;
      _point_type * point;
      enum { JointType_SpineBase = 0 };
      enum { JointType_SpineMid = 1 };
      enum { JointType_Neck = 2 };
      enum { JointType_Head = 3 };
      enum { JointType_ShoulderLeft = 4 };
      enum { JointType_ElbowLeft = 5 };
      enum { JointType_WristLeft = 6 };
      enum { JointType_HandLeft = 7 };
      enum { JointType_ShoulderRight = 8 };
      enum { JointType_ElbowRight = 9 };
      enum { JointType_WristRight = 10 };
      enum { JointType_HandRight = 11 };
      enum { JointType_HipLeft = 12 };
      enum { JointType_KneeLeft = 13 };
      enum { JointType_AnkleLeft = 14 };
      enum { JointType_FootLeft = 15 };
      enum { JointType_HipRight = 16 };
      enum { JointType_KneeRight = 17 };
      enum { JointType_AnkleRight = 18 };
      enum { JointType_FootRight = 19 };
      enum { JointType_SpineShoulder = 20 };
      enum { JointType_HandTipLeft = 21 };
      enum { JointType_ThumbLeft = 22 };
      enum { JointType_HandTipRight = 23 };
      enum { JointType_ThumbRight = 24 };
      enum { JointType_Count = 25 };
      enum { TrackingState_NotTracked = 0 };
      enum { TrackingState_Inferred = 1 };
      enum { TrackingState_Tracked = 2 };

    HumanSkeletonV2():
      header(),
      point_length(0), point(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->point_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_length);
      for( uint32_t i = 0; i < point_length; i++){
      offset += this->point[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t point_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_length);
      if(point_lengthT > point_length)
        this->point = (geometry_msgs::Point*)realloc(this->point, point_lengthT * sizeof(geometry_msgs::Point));
      point_length = point_lengthT;
      for( uint32_t i = 0; i < point_length; i++){
      offset += this->st_point.deserialize(inbuffer + offset);
        memcpy( &(this->point[i]), &(this->st_point), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "gait_training_robot/HumanSkeletonV2"; };
    const char * getMD5(){ return "d613d21ba87e255b15ca65a616b93a8c"; };

  };

}
#endif