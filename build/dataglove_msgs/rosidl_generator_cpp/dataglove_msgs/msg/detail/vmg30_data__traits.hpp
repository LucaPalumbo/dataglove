// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dataglove_msgs/msg/vmg30_data.hpp"


#ifndef DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__TRAITS_HPP_
#define DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dataglove_msgs/msg/detail/vmg30_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dataglove_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VMG30Data & msg,
  std::ostream & out)
{
  out << "{";
  // member: packet_tick
  {
    out << "packet_tick: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_tick, out);
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: sensors
  {
    if (msg.sensors.size() == 0) {
      out << "sensors: []";
    } else {
      out << "sensors: [";
      size_t pending_items = msg.sensors.size();
      for (auto item : msg.sensors) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: rpy_hand
  {
    if (msg.rpy_hand.size() == 0) {
      out << "rpy_hand: []";
    } else {
      out << "rpy_hand: [";
      size_t pending_items = msg.rpy_hand.size();
      for (auto item : msg.rpy_hand) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: quat_hand
  {
    if (msg.quat_hand.size() == 0) {
      out << "quat_hand: []";
    } else {
      out << "quat_hand: [";
      size_t pending_items = msg.quat_hand.size();
      for (auto item : msg.quat_hand) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: rpy_forearm
  {
    if (msg.rpy_forearm.size() == 0) {
      out << "rpy_forearm: []";
    } else {
      out << "rpy_forearm: [";
      size_t pending_items = msg.rpy_forearm.size();
      for (auto item : msg.rpy_forearm) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: quat_forearm
  {
    if (msg.quat_forearm.size() == 0) {
      out << "quat_forearm: []";
    } else {
      out << "quat_forearm: [";
      size_t pending_items = msg.quat_forearm.size();
      for (auto item : msg.quat_forearm) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VMG30Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: packet_tick
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "packet_tick: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_tick, out);
    out << "\n";
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: sensors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sensors.size() == 0) {
      out << "sensors: []\n";
    } else {
      out << "sensors:\n";
      for (auto item : msg.sensors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rpy_hand
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rpy_hand.size() == 0) {
      out << "rpy_hand: []\n";
    } else {
      out << "rpy_hand:\n";
      for (auto item : msg.rpy_hand) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: quat_hand
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.quat_hand.size() == 0) {
      out << "quat_hand: []\n";
    } else {
      out << "quat_hand:\n";
      for (auto item : msg.quat_hand) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rpy_forearm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rpy_forearm.size() == 0) {
      out << "rpy_forearm: []\n";
    } else {
      out << "rpy_forearm:\n";
      for (auto item : msg.rpy_forearm) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: quat_forearm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.quat_forearm.size() == 0) {
      out << "quat_forearm: []\n";
    } else {
      out << "quat_forearm:\n";
      for (auto item : msg.quat_forearm) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VMG30Data & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dataglove_msgs

namespace rosidl_generator_traits
{

[[deprecated("use dataglove_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dataglove_msgs::msg::VMG30Data & msg,
  std::ostream & out, size_t indentation = 0)
{
  dataglove_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dataglove_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dataglove_msgs::msg::VMG30Data & msg)
{
  return dataglove_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dataglove_msgs::msg::VMG30Data>()
{
  return "dataglove_msgs::msg::VMG30Data";
}

template<>
inline const char * name<dataglove_msgs::msg::VMG30Data>()
{
  return "dataglove_msgs/msg/VMG30Data";
}

template<>
struct has_fixed_size<dataglove_msgs::msg::VMG30Data>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dataglove_msgs::msg::VMG30Data>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dataglove_msgs::msg::VMG30Data>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__TRAITS_HPP_
