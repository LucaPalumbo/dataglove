// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dataglove_msgs/msg/vmg30_data.h"


#ifndef DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__STRUCT_H_
#define DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'sensors'
// Member 'rpy_hand'
// Member 'quat_hand'
// Member 'rpy_forearm'
// Member 'quat_forearm'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/VMG30Data in the package dataglove_msgs.
typedef struct dataglove_msgs__msg__VMG30Data
{
  /// 16 values
  rosidl_runtime_c__float__Sequence sensors;
  /// 3 values (roll, pitch, yaw)
  rosidl_runtime_c__float__Sequence rpy_hand;
  /// 4 values (w, x, y, z)
  rosidl_runtime_c__float__Sequence quat_hand;
  /// 3 values
  rosidl_runtime_c__float__Sequence rpy_forearm;
  /// 4 values
  rosidl_runtime_c__float__Sequence quat_forearm;
} dataglove_msgs__msg__VMG30Data;

// Struct for a sequence of dataglove_msgs__msg__VMG30Data.
typedef struct dataglove_msgs__msg__VMG30Data__Sequence
{
  dataglove_msgs__msg__VMG30Data * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dataglove_msgs__msg__VMG30Data__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__STRUCT_H_
