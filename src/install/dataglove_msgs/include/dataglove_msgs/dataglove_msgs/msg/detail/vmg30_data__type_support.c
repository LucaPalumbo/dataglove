// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dataglove_msgs/msg/detail/vmg30_data__rosidl_typesupport_introspection_c.h"
#include "dataglove_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dataglove_msgs/msg/detail/vmg30_data__functions.h"
#include "dataglove_msgs/msg/detail/vmg30_data__struct.h"


// Include directives for member types
// Member `sensors`
// Member `rpy_hand`
// Member `quat_hand`
// Member `rpy_forearm`
// Member `quat_forearm`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dataglove_msgs__msg__VMG30Data__init(message_memory);
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_fini_function(void * message_memory)
{
  dataglove_msgs__msg__VMG30Data__fini(message_memory);
}

size_t dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__sensors(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__sensors(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__sensors(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__sensors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__sensors(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__sensors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__sensors(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__sensors(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__rpy_hand(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__rpy_hand(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__rpy_hand(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__rpy_hand(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__rpy_hand(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__rpy_hand(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__rpy_hand(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__rpy_hand(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__quat_hand(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__quat_hand(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__quat_hand(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__quat_hand(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__quat_hand(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__quat_hand(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__quat_hand(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__quat_hand(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__rpy_forearm(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__rpy_forearm(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__rpy_forearm(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__rpy_forearm(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__rpy_forearm(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__rpy_forearm(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__rpy_forearm(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__rpy_forearm(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__quat_forearm(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__quat_forearm(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__quat_forearm(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__quat_forearm(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__quat_forearm(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__quat_forearm(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__quat_forearm(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__quat_forearm(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_member_array[5] = {
  {
    "sensors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs__msg__VMG30Data, sensors),  // bytes offset in struct
    NULL,  // default value
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__sensors,  // size() function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__sensors,  // get_const(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__sensors,  // get(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__sensors,  // fetch(index, &value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__sensors,  // assign(index, value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__sensors  // resize(index) function pointer
  },
  {
    "rpy_hand",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs__msg__VMG30Data, rpy_hand),  // bytes offset in struct
    NULL,  // default value
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__rpy_hand,  // size() function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__rpy_hand,  // get_const(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__rpy_hand,  // get(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__rpy_hand,  // fetch(index, &value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__rpy_hand,  // assign(index, value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__rpy_hand  // resize(index) function pointer
  },
  {
    "quat_hand",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs__msg__VMG30Data, quat_hand),  // bytes offset in struct
    NULL,  // default value
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__quat_hand,  // size() function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__quat_hand,  // get_const(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__quat_hand,  // get(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__quat_hand,  // fetch(index, &value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__quat_hand,  // assign(index, value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__quat_hand  // resize(index) function pointer
  },
  {
    "rpy_forearm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs__msg__VMG30Data, rpy_forearm),  // bytes offset in struct
    NULL,  // default value
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__rpy_forearm,  // size() function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__rpy_forearm,  // get_const(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__rpy_forearm,  // get(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__rpy_forearm,  // fetch(index, &value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__rpy_forearm,  // assign(index, value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__rpy_forearm  // resize(index) function pointer
  },
  {
    "quat_forearm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dataglove_msgs__msg__VMG30Data, quat_forearm),  // bytes offset in struct
    NULL,  // default value
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__size_function__VMG30Data__quat_forearm,  // size() function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_const_function__VMG30Data__quat_forearm,  // get_const(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__get_function__VMG30Data__quat_forearm,  // get(index) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__fetch_function__VMG30Data__quat_forearm,  // fetch(index, &value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__assign_function__VMG30Data__quat_forearm,  // assign(index, value) function pointer
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__resize_function__VMG30Data__quat_forearm  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_members = {
  "dataglove_msgs__msg",  // message namespace
  "VMG30Data",  // message name
  5,  // number of fields
  sizeof(dataglove_msgs__msg__VMG30Data),
  false,  // has_any_key_member_
  dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_member_array,  // message members
  dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_init_function,  // function to initialize message memory (memory has to be allocated)
  dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_type_support_handle = {
  0,
  &dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_members,
  get_message_typesupport_handle_function,
  &dataglove_msgs__msg__VMG30Data__get_type_hash,
  &dataglove_msgs__msg__VMG30Data__get_type_description,
  &dataglove_msgs__msg__VMG30Data__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dataglove_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dataglove_msgs, msg, VMG30Data)() {
  if (!dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_type_support_handle.typesupport_identifier) {
    dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dataglove_msgs__msg__VMG30Data__rosidl_typesupport_introspection_c__VMG30Data_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
