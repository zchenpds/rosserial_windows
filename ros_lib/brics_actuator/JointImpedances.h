#ifndef _ROS_brics_actuator_JointImpedances_h
#define _ROS_brics_actuator_JointImpedances_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "brics_actuator/Poison.h"
#include "brics_actuator/JointValue.h"

namespace brics_actuator
{

  class JointImpedances : public ros::Msg
  {
    public:
      typedef brics_actuator::Poison _poisonStamp_type;
      _poisonStamp_type poisonStamp;
      uint32_t dampings_length;
      typedef brics_actuator::JointValue _dampings_type;
      _dampings_type st_dampings;
      _dampings_type * dampings;
      uint32_t stiffnesses_length;
      typedef brics_actuator::JointValue _stiffnesses_type;
      _stiffnesses_type st_stiffnesses;
      _stiffnesses_type * stiffnesses;

    JointImpedances():
      poisonStamp(),
      dampings_length(0), dampings(NULL),
      stiffnesses_length(0), stiffnesses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->poisonStamp.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->dampings_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dampings_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dampings_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dampings_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dampings_length);
      for( uint32_t i = 0; i < dampings_length; i++){
      offset += this->dampings[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->stiffnesses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stiffnesses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stiffnesses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stiffnesses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stiffnesses_length);
      for( uint32_t i = 0; i < stiffnesses_length; i++){
      offset += this->stiffnesses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->poisonStamp.deserialize(inbuffer + offset);
      uint32_t dampings_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dampings_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dampings_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dampings_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dampings_length);
      if(dampings_lengthT > dampings_length)
        this->dampings = (brics_actuator::JointValue*)realloc(this->dampings, dampings_lengthT * sizeof(brics_actuator::JointValue));
      dampings_length = dampings_lengthT;
      for( uint32_t i = 0; i < dampings_length; i++){
      offset += this->st_dampings.deserialize(inbuffer + offset);
        memcpy( &(this->dampings[i]), &(this->st_dampings), sizeof(brics_actuator::JointValue));
      }
      uint32_t stiffnesses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stiffnesses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stiffnesses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stiffnesses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stiffnesses_length);
      if(stiffnesses_lengthT > stiffnesses_length)
        this->stiffnesses = (brics_actuator::JointValue*)realloc(this->stiffnesses, stiffnesses_lengthT * sizeof(brics_actuator::JointValue));
      stiffnesses_length = stiffnesses_lengthT;
      for( uint32_t i = 0; i < stiffnesses_length; i++){
      offset += this->st_stiffnesses.deserialize(inbuffer + offset);
        memcpy( &(this->stiffnesses[i]), &(this->st_stiffnesses), sizeof(brics_actuator::JointValue));
      }
     return offset;
    }

    const char * getType(){ return "brics_actuator/JointImpedances"; };
    const char * getMD5(){ return "14fdbb76121290f17525acd99e7242c6"; };

  };

}
#endif