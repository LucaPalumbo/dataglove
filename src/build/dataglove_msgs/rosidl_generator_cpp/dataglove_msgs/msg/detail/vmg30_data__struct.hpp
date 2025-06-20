// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dataglove_msgs/msg/vmg30_data.hpp"


#ifndef DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__STRUCT_HPP_
#define DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dataglove_msgs__msg__VMG30Data __attribute__((deprecated))
#else
# define DEPRECATED__dataglove_msgs__msg__VMG30Data __declspec(deprecated)
#endif

namespace dataglove_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VMG30Data_
{
  using Type = VMG30Data_<ContainerAllocator>;

  explicit VMG30Data_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit VMG30Data_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _sensors_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _sensors_type sensors;
  using _rpy_hand_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _rpy_hand_type rpy_hand;
  using _quat_hand_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _quat_hand_type quat_hand;
  using _rpy_forearm_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _rpy_forearm_type rpy_forearm;
  using _quat_forearm_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _quat_forearm_type quat_forearm;

  // setters for named parameter idiom
  Type & set__sensors(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->sensors = _arg;
    return *this;
  }
  Type & set__rpy_hand(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->rpy_hand = _arg;
    return *this;
  }
  Type & set__quat_hand(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->quat_hand = _arg;
    return *this;
  }
  Type & set__rpy_forearm(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->rpy_forearm = _arg;
    return *this;
  }
  Type & set__quat_forearm(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->quat_forearm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dataglove_msgs::msg::VMG30Data_<ContainerAllocator> *;
  using ConstRawPtr =
    const dataglove_msgs::msg::VMG30Data_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dataglove_msgs::msg::VMG30Data_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dataglove_msgs::msg::VMG30Data_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dataglove_msgs__msg__VMG30Data
    std::shared_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dataglove_msgs__msg__VMG30Data
    std::shared_ptr<dataglove_msgs::msg::VMG30Data_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VMG30Data_ & other) const
  {
    if (this->sensors != other.sensors) {
      return false;
    }
    if (this->rpy_hand != other.rpy_hand) {
      return false;
    }
    if (this->quat_hand != other.quat_hand) {
      return false;
    }
    if (this->rpy_forearm != other.rpy_forearm) {
      return false;
    }
    if (this->quat_forearm != other.quat_forearm) {
      return false;
    }
    return true;
  }
  bool operator!=(const VMG30Data_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VMG30Data_

// alias to use template instance with default allocator
using VMG30Data =
  dataglove_msgs::msg::VMG30Data_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dataglove_msgs

#endif  // DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__STRUCT_HPP_
