// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dataglove_msgs/msg/detail/vmg30_data__functions.h"
#include "dataglove_msgs/msg/detail/vmg30_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dataglove_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void VMG30Data_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dataglove_msgs::msg::VMG30Data(_init);
}

void VMG30Data_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dataglove_msgs::msg::VMG30Data *>(message_memory);
  typed_message->~VMG30Data();
}

size_t size_function__VMG30Data__sensors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VMG30Data__sensors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__VMG30Data__sensors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__VMG30Data__sensors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__VMG30Data__sensors(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__VMG30Data__sensors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__VMG30Data__sensors(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__VMG30Data__sensors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__VMG30Data__rpy_hand(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VMG30Data__rpy_hand(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__VMG30Data__rpy_hand(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__VMG30Data__rpy_hand(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__VMG30Data__rpy_hand(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__VMG30Data__rpy_hand(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__VMG30Data__rpy_hand(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__VMG30Data__rpy_hand(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__VMG30Data__quat_hand(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VMG30Data__quat_hand(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__VMG30Data__quat_hand(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__VMG30Data__quat_hand(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__VMG30Data__quat_hand(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__VMG30Data__quat_hand(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__VMG30Data__quat_hand(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__VMG30Data__quat_hand(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__VMG30Data__rpy_forearm(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VMG30Data__rpy_forearm(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__VMG30Data__rpy_forearm(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__VMG30Data__rpy_forearm(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__VMG30Data__rpy_forearm(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__VMG30Data__rpy_forearm(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__VMG30Data__rpy_forearm(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__VMG30Data__rpy_forearm(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__VMG30Data__quat_forearm(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__VMG30Data__quat_forearm(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__VMG30Data__quat_forearm(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__VMG30Data__quat_forearm(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__VMG30Data__quat_forearm(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__VMG30Data__quat_forearm(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__VMG30Data__quat_forearm(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__VMG30Data__quat_forearm(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember VMG30Data_message_member_array[7] = {
  {
    "packet_tick",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs::msg::VMG30Data, packet_tick),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs::msg::VMG30Data, time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sensors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs::msg::VMG30Data, sensors),  // bytes offset in struct
    nullptr,  // default value
    size_function__VMG30Data__sensors,  // size() function pointer
    get_const_function__VMG30Data__sensors,  // get_const(index) function pointer
    get_function__VMG30Data__sensors,  // get(index) function pointer
    fetch_function__VMG30Data__sensors,  // fetch(index, &value) function pointer
    assign_function__VMG30Data__sensors,  // assign(index, value) function pointer
    resize_function__VMG30Data__sensors  // resize(index) function pointer
  },
  {
    "rpy_hand",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs::msg::VMG30Data, rpy_hand),  // bytes offset in struct
    nullptr,  // default value
    size_function__VMG30Data__rpy_hand,  // size() function pointer
    get_const_function__VMG30Data__rpy_hand,  // get_const(index) function pointer
    get_function__VMG30Data__rpy_hand,  // get(index) function pointer
    fetch_function__VMG30Data__rpy_hand,  // fetch(index, &value) function pointer
    assign_function__VMG30Data__rpy_hand,  // assign(index, value) function pointer
    resize_function__VMG30Data__rpy_hand  // resize(index) function pointer
  },
  {
    "quat_hand",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs::msg::VMG30Data, quat_hand),  // bytes offset in struct
    nullptr,  // default value
    size_function__VMG30Data__quat_hand,  // size() function pointer
    get_const_function__VMG30Data__quat_hand,  // get_const(index) function pointer
    get_function__VMG30Data__quat_hand,  // get(index) function pointer
    fetch_function__VMG30Data__quat_hand,  // fetch(index, &value) function pointer
    assign_function__VMG30Data__quat_hand,  // assign(index, value) function pointer
    resize_function__VMG30Data__quat_hand  // resize(index) function pointer
  },
  {
    "rpy_forearm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs::msg::VMG30Data, rpy_forearm),  // bytes offset in struct
    nullptr,  // default value
    size_function__VMG30Data__rpy_forearm,  // size() function pointer
    get_const_function__VMG30Data__rpy_forearm,  // get_const(index) function pointer
    get_function__VMG30Data__rpy_forearm,  // get(index) function pointer
    fetch_function__VMG30Data__rpy_forearm,  // fetch(index, &value) function pointer
    assign_function__VMG30Data__rpy_forearm,  // assign(index, value) function pointer
    resize_function__VMG30Data__rpy_forearm  // resize(index) function pointer
  },
  {
    "quat_forearm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs::msg::VMG30Data, quat_forearm),  // bytes offset in struct
    nullptr,  // default value
    size_function__VMG30Data__quat_forearm,  // size() function pointer
    get_const_function__VMG30Data__quat_forearm,  // get_const(index) function pointer
    get_function__VMG30Data__quat_forearm,  // get(index) function pointer
    fetch_function__VMG30Data__quat_forearm,  // fetch(index, &value) function pointer
    assign_function__VMG30Data__quat_forearm,  // assign(index, value) function pointer
    resize_function__VMG30Data__quat_forearm  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers VMG30Data_message_members = {
  "dataglove_msgs::msg",  // message namespace
  "VMG30Data",  // message name
  7,  // number of fields
  sizeof(dataglove_msgs::msg::VMG30Data),
  false,  // has_any_key_member_
  VMG30Data_message_member_array,  // message members
  VMG30Data_init_function,  // function to initialize message memory (memory has to be allocated)
  VMG30Data_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t VMG30Data_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &VMG30Data_message_members,
  get_message_typesupport_handle_function,
  &dataglove_msgs__msg__VMG30Data__get_type_hash,
  &dataglove_msgs__msg__VMG30Data__get_type_description,
  &dataglove_msgs__msg__VMG30Data__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dataglove_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dataglove_msgs::msg::VMG30Data>()
{
  return &::dataglove_msgs::msg::rosidl_typesupport_introspection_cpp::VMG30Data_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dataglove_msgs, msg, VMG30Data)() {
  return &::dataglove_msgs::msg::rosidl_typesupport_introspection_cpp::VMG30Data_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
