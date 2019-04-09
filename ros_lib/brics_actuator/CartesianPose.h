#ifndef _ROS_brics_actuator_CartesianPose_h
#define _ROS_brics_actuator_CartesianPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/CartesianVector.h"
#include "geometry_msgs/Quaternion.h"

namespace brics_actuator
{

  class CartesianPose : public ros::Msg
  {
    public:
      typedef ros::Time _timeStamp_type;
      _timeStamp_type timeStamp;
      typedef brics_actuator::Poison _poisonStamp_type;
      _poisonStamp_type poisonStamp;
      typedef const char* _base_frame_uri_type;
      _base_frame_uri_type base_frame_uri;
      typedef const char* _target_frame_uri_type;
      _target_frame_uri_type target_frame_uri;
      typedef brics_actuator::CartesianVector _position_type;
      _position_type position;
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;

    CartesianPose():
      timeStamp(),
      poisonStamp(),
      base_frame_uri(""),
      target_frame_uri(""),
      position(),
      orientation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->timeStamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeStamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeStamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeStamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeStamp.sec);
      *(outbuffer + offset + 0) = (this->timeStamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeStamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeStamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeStamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeStamp.nsec);
      offset += this->poisonStamp.serialize(outbuffer + offset);
      uint32_t length_base_frame_uri = strlen(this->base_frame_uri);
      varToArr(outbuffer + offset, length_base_frame_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->base_frame_uri, length_base_frame_uri);
      offset += length_base_frame_uri;
      uint32_t length_target_frame_uri = strlen(this->target_frame_uri);
      varToArr(outbuffer + offset, length_target_frame_uri);
      offset += 4;
      memcpy(outbuffer + offset, this->target_frame_uri, length_target_frame_uri);
      offset += length_target_frame_uri;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->timeStamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeStamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeStamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeStamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeStamp.sec);
      this->timeStamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeStamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeStamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeStamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeStamp.nsec);
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      uint32_t length_base_frame_uri;
      arrToVar(length_base_frame_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_base_frame_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_base_frame_uri-1]=0;
      this->base_frame_uri = (char *)(inbuffer + offset-1);
      offset += length_base_frame_uri;
      uint32_t length_target_frame_uri;
      arrToVar(length_target_frame_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_frame_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_frame_uri-1]=0;
      this->target_frame_uri = (char *)(inbuffer + offset-1);
      offset += length_target_frame_uri;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "brics_actuator/CartesianPose"; };
    const char * getMD5(){ return "0fe287468091771914ed98dea2d2a5a5"; };

  };

}
#endif