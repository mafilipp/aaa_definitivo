/* Auto-generated by genmsg_cpp for file /home/mafilipp/fuerte_workspace/sandbox/aaa_definitivo/msg/waypoint.msg */
#ifndef AAA_DEFINITIVO_MESSAGE_WAYPOINT_H
#define AAA_DEFINITIVO_MESSAGE_WAYPOINT_H
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

namespace aaa_definitivo
{
template <class ContainerAllocator>
struct waypoint_ {
  typedef waypoint_<ContainerAllocator> Type;

  waypoint_()
  : header()
  , waypoint_x(0.0)
  , waypoint_y(0.0)
  , waypoint_z(0.0)
  , waypoint_psi(0.0)
  {
  }

  waypoint_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , waypoint_x(0.0)
  , waypoint_y(0.0)
  , waypoint_z(0.0)
  , waypoint_psi(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef double _waypoint_x_type;
  double waypoint_x;

  typedef double _waypoint_y_type;
  double waypoint_y;

  typedef double _waypoint_z_type;
  double waypoint_z;

  typedef double _waypoint_psi_type;
  double waypoint_psi;


  typedef boost::shared_ptr< ::aaa_definitivo::waypoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::aaa_definitivo::waypoint_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct waypoint
typedef  ::aaa_definitivo::waypoint_<std::allocator<void> > waypoint;

typedef boost::shared_ptr< ::aaa_definitivo::waypoint> waypointPtr;
typedef boost::shared_ptr< ::aaa_definitivo::waypoint const> waypointConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::aaa_definitivo::waypoint_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::aaa_definitivo::waypoint_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace aaa_definitivo

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::aaa_definitivo::waypoint_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::aaa_definitivo::waypoint_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::aaa_definitivo::waypoint_<ContainerAllocator> > {
  static const char* value() 
  {
    return "2acafb9604ce5593f72837a14273dd01";
  }

  static const char* value(const  ::aaa_definitivo::waypoint_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x2acafb9604ce5593ULL;
  static const uint64_t static_value2 = 0xf72837a14273dd01ULL;
};

template<class ContainerAllocator>
struct DataType< ::aaa_definitivo::waypoint_<ContainerAllocator> > {
  static const char* value() 
  {
    return "aaa_definitivo/waypoint";
  }

  static const char* value(const  ::aaa_definitivo::waypoint_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::aaa_definitivo::waypoint_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header    header\n\
\n\
float64 waypoint_x\n\
float64 waypoint_y\n\
float64 waypoint_z\n\
float64 waypoint_psi\n\
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

  static const char* value(const  ::aaa_definitivo::waypoint_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::aaa_definitivo::waypoint_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::aaa_definitivo::waypoint_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::aaa_definitivo::waypoint_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.waypoint_x);
    stream.next(m.waypoint_y);
    stream.next(m.waypoint_z);
    stream.next(m.waypoint_psi);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct waypoint_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::aaa_definitivo::waypoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::aaa_definitivo::waypoint_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "waypoint_x: ";
    Printer<double>::stream(s, indent + "  ", v.waypoint_x);
    s << indent << "waypoint_y: ";
    Printer<double>::stream(s, indent + "  ", v.waypoint_y);
    s << indent << "waypoint_z: ";
    Printer<double>::stream(s, indent + "  ", v.waypoint_z);
    s << indent << "waypoint_psi: ";
    Printer<double>::stream(s, indent + "  ", v.waypoint_psi);
  }
};


} // namespace message_operations
} // namespace ros

#endif // AAA_DEFINITIVO_MESSAGE_WAYPOINT_H

