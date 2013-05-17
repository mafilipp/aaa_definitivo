/* Auto-generated by genmsg_cpp for file /home/mafilipp/fuerte_workspace/sandbox/sl_controller/msg/AngleMeasStamped.msg */
#ifndef SL_CONTROLLER_MESSAGE_ANGLEMEASSTAMPED_H
#define SL_CONTROLLER_MESSAGE_ANGLEMEASSTAMPED_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace sl_controller
{
template <class ContainerAllocator>
struct AngleMeasStamped_ {
  typedef AngleMeasStamped_<ContainerAllocator> Type;

  AngleMeasStamped_()
  : header()
  , theta(0.0)
  , phi(0.0)
  {
  }

  AngleMeasStamped_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , theta(0.0)
  , phi(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef double _theta_type;
  double theta;

  typedef double _phi_type;
  double phi;


  typedef boost::shared_ptr< ::sl_controller::AngleMeasStamped_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sl_controller::AngleMeasStamped_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct AngleMeasStamped
typedef  ::sl_controller::AngleMeasStamped_<std::allocator<void> > AngleMeasStamped;

typedef boost::shared_ptr< ::sl_controller::AngleMeasStamped> AngleMeasStampedPtr;
typedef boost::shared_ptr< ::sl_controller::AngleMeasStamped const> AngleMeasStampedConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::sl_controller::AngleMeasStamped_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::sl_controller::AngleMeasStamped_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace sl_controller

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::sl_controller::AngleMeasStamped_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::sl_controller::AngleMeasStamped_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::sl_controller::AngleMeasStamped_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d5b6306d616b12d92ce706280607d735";
  }

  static const char* value(const  ::sl_controller::AngleMeasStamped_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd5b6306d616b12d9ULL;
  static const uint64_t static_value2 = 0x2ce706280607d735ULL;
};

template<class ContainerAllocator>
struct DataType< ::sl_controller::AngleMeasStamped_<ContainerAllocator> > {
  static const char* value() 
  {
    return "sl_controller/AngleMeasStamped";
  }

  static const char* value(const  ::sl_controller::AngleMeasStamped_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::sl_controller::AngleMeasStamped_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
float64 theta\n\
float64 phi\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::sl_controller::AngleMeasStamped_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::sl_controller::AngleMeasStamped_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::sl_controller::AngleMeasStamped_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::sl_controller::AngleMeasStamped_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.theta);
    stream.next(m.phi);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct AngleMeasStamped_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sl_controller::AngleMeasStamped_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::sl_controller::AngleMeasStamped_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "theta: ";
    Printer<double>::stream(s, indent + "  ", v.theta);
    s << indent << "phi: ";
    Printer<double>::stream(s, indent + "  ", v.phi);
  }
};


} // namespace message_operations
} // namespace ros

#endif // SL_CONTROLLER_MESSAGE_ANGLEMEASSTAMPED_H

