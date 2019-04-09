#ifndef _ROS_brics_actuator_JointPositions_h
#define _ROS_brics_actuator_JointPositions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"

namespace brics_actuator
{

  class JointPositions : public ros::Msg
  {
    public:
      typedef brics_actuator::Poison _poisonStamp_type;
      _poisonStamp_type poisonStamp;
      uint32_t positions_length;
      typedef brics_actuator::JointValue _positions_type;
      _positions_type st_positions;
      _positions_type * positions;

    JointPositions():
      poisonStamp(),
      positions_length(0), positions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++){
      offset += this->positions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (brics_actuator::JointValue*)realloc(this->positions, positions_lengthT * sizeof(brics_actuator::JointValue));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++){
      offset += this->st_positions.deserialize(inbuffer + offset);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(brics_actuator::JointValue));
      }
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointPositions"; };
    const char * getMD5(){ return "2b7638f5c85f5257bef140a00cd0eec3"; };

  };

}
#endif