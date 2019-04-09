#ifndef _ROS_brics_actuator_JointVelocities_h
#define _ROS_brics_actuator_JointVelocities_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"

namespace brics_actuator
{

  class JointVelocities : public ros::Msg
  {
    public:
      typedef brics_actuator::Poison _poisonStamp_type;
      _poisonStamp_type poisonStamp;
      uint32_t velocities_length;
      typedef brics_actuator::JointValue _velocities_type;
      _velocities_type st_velocities;
      _velocities_type * velocities;

    JointVelocities():
      poisonStamp(),
      velocities_length(0), velocities(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->velocities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++){
      offset += this->velocities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      uint32_t velocities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocities_length);
      if(velocities_lengthT > velocities_length)
        this->velocities = (brics_actuator::JointValue*)realloc(this->velocities, velocities_lengthT * sizeof(brics_actuator::JointValue));
      velocities_length = velocities_lengthT;
      for( uint32_t i = 0; i < velocities_length; i++){
      offset += this->st_velocities.deserialize(inbuffer + offset);
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(brics_actuator::JointValue));
      }
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointVelocities"; };
    const char * getMD5(){ return "9786afc900be50b3ba4113fcb65c9363"; };

  };

}
#endif