// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dataglove_msgs/msg/vmg30_data.hpp"


#ifndef DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__BUILDER_HPP_
#define DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dataglove_msgs/msg/detail/vmg30_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dataglove_msgs
{

namespace msg
{

namespace builder
{

class Init_VMG30Data_quat_forearm
{
public:
  explicit Init_VMG30Data_quat_forearm(::dataglove_msgs::msg::VMG30Data & msg)
  : msg_(msg)
  {}
  ::dataglove_msgs::msg::VMG30Data quat_forearm(::dataglove_msgs::msg::VMG30Data::_quat_forearm_type arg)
  {
    msg_.quat_forearm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dataglove_msgs::msg::VMG30Data msg_;
};

class Init_VMG30Data_rpy_forearm
{
public:
  explicit Init_VMG30Data_rpy_forearm(::dataglove_msgs::msg::VMG30Data & msg)
  : msg_(msg)
  {}
  Init_VMG30Data_quat_forearm rpy_forearm(::dataglove_msgs::msg::VMG30Data::_rpy_forearm_type arg)
  {
    msg_.rpy_forearm = std::move(arg);
    return Init_VMG30Data_quat_forearm(msg_);
  }

private:
  ::dataglove_msgs::msg::VMG30Data msg_;
};

class Init_VMG30Data_quat_hand
{
public:
  explicit Init_VMG30Data_quat_hand(::dataglove_msgs::msg::VMG30Data & msg)
  : msg_(msg)
  {}
  Init_VMG30Data_rpy_forearm quat_hand(::dataglove_msgs::msg::VMG30Data::_quat_hand_type arg)
  {
    msg_.quat_hand = std::move(arg);
    return Init_VMG30Data_rpy_forearm(msg_);
  }

private:
  ::dataglove_msgs::msg::VMG30Data msg_;
};

class Init_VMG30Data_rpy_hand
{
public:
  explicit Init_VMG30Data_rpy_hand(::dataglove_msgs::msg::VMG30Data & msg)
  : msg_(msg)
  {}
  Init_VMG30Data_quat_hand rpy_hand(::dataglove_msgs::msg::VMG30Data::_rpy_hand_type arg)
  {
    msg_.rpy_hand = std::move(arg);
    return Init_VMG30Data_quat_hand(msg_);
  }

private:
  ::dataglove_msgs::msg::VMG30Data msg_;
};

class Init_VMG30Data_sensors
{
public:
  explicit Init_VMG30Data_sensors(::dataglove_msgs::msg::VMG30Data & msg)
  : msg_(msg)
  {}
  Init_VMG30Data_rpy_hand sensors(::dataglove_msgs::msg::VMG30Data::_sensors_type arg)
  {
    msg_.sensors = std::move(arg);
    return Init_VMG30Data_rpy_hand(msg_);
  }

private:
  ::dataglove_msgs::msg::VMG30Data msg_;
};

class Init_VMG30Data_time
{
public:
  explicit Init_VMG30Data_time(::dataglove_msgs::msg::VMG30Data & msg)
  : msg_(msg)
  {}
  Init_VMG30Data_sensors time(::dataglove_msgs::msg::VMG30Data::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_VMG30Data_sensors(msg_);
  }

private:
  ::dataglove_msgs::msg::VMG30Data msg_;
};

class Init_VMG30Data_packet_tick
{
public:
  Init_VMG30Data_packet_tick()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VMG30Data_time packet_tick(::dataglove_msgs::msg::VMG30Data::_packet_tick_type arg)
  {
    msg_.packet_tick = std::move(arg);
    return Init_VMG30Data_time(msg_);
  }

private:
  ::dataglove_msgs::msg::VMG30Data msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dataglove_msgs::msg::VMG30Data>()
{
  return dataglove_msgs::msg::builder::Init_VMG30Data_packet_tick();
}

}  // namespace dataglove_msgs

#endif  // DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__BUILDER_HPP_
