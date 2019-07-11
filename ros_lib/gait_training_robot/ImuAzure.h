#ifndef _ROS_gait_training_robot_ImuAzure_h
#define _ROS_gait_training_robot_ImuAzure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace gait_training_robot
{

  class ImuAzure : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _acc_timestamp_usec_type;
      _acc_timestamp_usec_type acc_timestamp_usec;
      typedef geometry_msgs::Vector3 _linear_acceleration_type;
      _linear_acceleration_type linear_acceleration;
      typedef uint64_t _gyro_timestamp_usec_type;
      _gyro_timestamp_usec_type gyro_timestamp_usec;
      typedef geometry_msgs::Vector3 _angular_velocity_type;
      _angular_velocity_type angular_velocity;

    ImuAzure():
      header(),
      acc_timestamp_usec(0),
      linear_acceleration(),
      gyro_timestamp_usec(0),
      angular_velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_acc_timestamp_usec;
      u_acc_timestamp_usec.real = this->acc_timestamp_usec;
      *(outbuffer + offset + 0) = (u_acc_timestamp_usec.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_timestamp_usec.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_timestamp_usec.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_timestamp_usec.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc_timestamp_usec);
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_gyro_timestamp_usec;
      u_gyro_timestamp_usec.real = this->gyro_timestamp_usec;
      *(outbuffer + offset + 0) = (u_gyro_timestamp_usec.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyro_timestamp_usec.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gyro_timestamp_usec.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gyro_timestamp_usec.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gyro_timestamp_usec);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_acc_timestamp_usec;
      u_acc_timestamp_usec.base = 0;
      u_acc_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->acc_timestamp_usec = u_acc_timestamp_usec.real;
      offset += sizeof(this->acc_timestamp_usec);
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_gyro_timestamp_usec;
      u_gyro_timestamp_usec.base = 0;
      u_gyro_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyro_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gyro_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gyro_timestamp_usec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gyro_timestamp_usec = u_gyro_timestamp_usec.real;
      offset += sizeof(this->gyro_timestamp_usec);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "gait_training_robot/ImuAzure"; };
    const char * getMD5(){ return "fee38aeaea90a8c9d2949769917da077"; };

  };

}
#endif