#ifndef _ROS_brics_actuator_JointTorques_h
#define _ROS_brics_actuator_JointTorques_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"

namespace brics_actuator
{

  class JointTorques : public ros::Msg
  {
    public:
      typedef brics_actuator::Poison _poisonStamp_type;
      _poisonStamp_type poisonStamp;
      uint32_t torques_length;
      typedef brics_actuator::JointValue _torques_type;
      _torques_type st_torques;
      _torques_type * torques;

    JointTorques():
      poisonStamp(),
      torques_length(0), torques(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->torques_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->torques_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->torques_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->torques_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->torques_length);
      for( uint32_t i = 0; i < torques_length; i++){
      offset += this->torques[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      uint32_t torques_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      torques_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      torques_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      torques_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->torques_length);
      if(torques_lengthT > torques_length)
        this->torques = (brics_actuator::JointValue*)realloc(this->torques, torques_lengthT * sizeof(brics_actuator::JointValue));
      torques_length = torques_lengthT;
      for( uint32_t i = 0; i < torques_length; i++){
      offset += this->st_torques.deserialize(inbuffer + offset);
        memcpy( &(this->torques[i]), &(this->st_torques), sizeof(brics_actuator::JointValue));
      }
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointTorques"; };
    const char * getMD5(){ return "75ccec429fa95e6b178bb9f3d06583e1"; };

  };

}
#endif