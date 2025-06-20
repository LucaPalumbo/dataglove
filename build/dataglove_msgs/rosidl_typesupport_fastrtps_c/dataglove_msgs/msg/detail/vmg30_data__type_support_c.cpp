// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice
#include "dataglove_msgs/msg/detail/vmg30_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dataglove_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dataglove_msgs/msg/detail/vmg30_data__struct.h"
#include "dataglove_msgs/msg/detail/vmg30_data__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // quat_forearm, quat_hand, rpy_forearm, rpy_hand, sensors
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // quat_forearm, quat_hand, rpy_forearm, rpy_hand, sensors

// forward declare type support functions


using _VMG30Data__ros_msg_type = dataglove_msgs__msg__VMG30Data;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dataglove_msgs
bool cdr_serialize_dataglove_msgs__msg__VMG30Data(
  const dataglove_msgs__msg__VMG30Data * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: packet_tick
  {
    cdr << ros_message->packet_tick;
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: sensors
  {
    size_t size = ros_message->sensors.size;
    auto array_ptr = ros_message->sensors.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rpy_hand
  {
    size_t size = ros_message->rpy_hand.size;
    auto array_ptr = ros_message->rpy_hand.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: quat_hand
  {
    size_t size = ros_message->quat_hand.size;
    auto array_ptr = ros_message->quat_hand.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rpy_forearm
  {
    size_t size = ros_message->rpy_forearm.size;
    auto array_ptr = ros_message->rpy_forearm.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: quat_forearm
  {
    size_t size = ros_message->quat_forearm.size;
    auto array_ptr = ros_message->quat_forearm.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dataglove_msgs
bool cdr_deserialize_dataglove_msgs__msg__VMG30Data(
  eprosima::fastcdr::Cdr & cdr,
  dataglove_msgs__msg__VMG30Data * ros_message)
{
  // Field name: packet_tick
  {
    cdr >> ros_message->packet_tick;
  }

  // Field name: time
  {
    cdr >> ros_message->time;
  }

  // Field name: sensors
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->sensors.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->sensors);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->sensors, size)) {
      fprintf(stderr, "failed to create array for field 'sensors'");
      return false;
    }
    auto array_ptr = ros_message->sensors.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: rpy_hand
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->rpy_hand.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->rpy_hand);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->rpy_hand, size)) {
      fprintf(stderr, "failed to create array for field 'rpy_hand'");
      return false;
    }
    auto array_ptr = ros_message->rpy_hand.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: quat_hand
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->quat_hand.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->quat_hand);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->quat_hand, size)) {
      fprintf(stderr, "failed to create array for field 'quat_hand'");
      return false;
    }
    auto array_ptr = ros_message->quat_hand.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: rpy_forearm
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->rpy_forearm.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->rpy_forearm);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->rpy_forearm, size)) {
      fprintf(stderr, "failed to create array for field 'rpy_forearm'");
      return false;
    }
    auto array_ptr = ros_message->rpy_forearm.data;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: quat_forearm
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->quat_forearm.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->quat_forearm);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->quat_forearm, size)) {
      fprintf(stderr, "failed to create array for field 'quat_forearm'");
      return false;
    }
    auto array_ptr = ros_message->quat_forearm.data;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dataglove_msgs
size_t get_serialized_size_dataglove_msgs__msg__VMG30Data(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VMG30Data__ros_msg_type * ros_message = static_cast<const _VMG30Data__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: packet_tick
  {
    size_t item_size = sizeof(ros_message->packet_tick);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: sensors
  {
    size_t array_size = ros_message->sensors.size;
    auto array_ptr = ros_message->sensors.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rpy_hand
  {
    size_t array_size = ros_message->rpy_hand.size;
    auto array_ptr = ros_message->rpy_hand.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: quat_hand
  {
    size_t array_size = ros_message->quat_hand.size;
    auto array_ptr = ros_message->quat_hand.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rpy_forearm
  {
    size_t array_size = ros_message->rpy_forearm.size;
    auto array_ptr = ros_message->rpy_forearm.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: quat_forearm
  {
    size_t array_size = ros_message->quat_forearm.size;
    auto array_ptr = ros_message->quat_forearm.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dataglove_msgs
size_t max_serialized_size_dataglove_msgs__msg__VMG30Data(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: packet_tick
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: sensors
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rpy_hand
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: quat_hand
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rpy_forearm
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: quat_forearm
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dataglove_msgs__msg__VMG30Data;
    is_plain =
      (
      offsetof(DataType, quat_forearm) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dataglove_msgs
bool cdr_serialize_key_dataglove_msgs__msg__VMG30Data(
  const dataglove_msgs__msg__VMG30Data * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: packet_tick
  {
    cdr << ros_message->packet_tick;
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  // Field name: sensors
  {
    size_t size = ros_message->sensors.size;
    auto array_ptr = ros_message->sensors.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rpy_hand
  {
    size_t size = ros_message->rpy_hand.size;
    auto array_ptr = ros_message->rpy_hand.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: quat_hand
  {
    size_t size = ros_message->quat_hand.size;
    auto array_ptr = ros_message->quat_hand.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: rpy_forearm
  {
    size_t size = ros_message->rpy_forearm.size;
    auto array_ptr = ros_message->rpy_forearm.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: quat_forearm
  {
    size_t size = ros_message->quat_forearm.size;
    auto array_ptr = ros_message->quat_forearm.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dataglove_msgs
size_t get_serialized_size_key_dataglove_msgs__msg__VMG30Data(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VMG30Data__ros_msg_type * ros_message = static_cast<const _VMG30Data__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: packet_tick
  {
    size_t item_size = sizeof(ros_message->packet_tick);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: sensors
  {
    size_t array_size = ros_message->sensors.size;
    auto array_ptr = ros_message->sensors.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rpy_hand
  {
    size_t array_size = ros_message->rpy_hand.size;
    auto array_ptr = ros_message->rpy_hand.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: quat_hand
  {
    size_t array_size = ros_message->quat_hand.size;
    auto array_ptr = ros_message->quat_hand.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rpy_forearm
  {
    size_t array_size = ros_message->rpy_forearm.size;
    auto array_ptr = ros_message->rpy_forearm.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: quat_forearm
  {
    size_t array_size = ros_message->quat_forearm.size;
    auto array_ptr = ros_message->quat_forearm.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dataglove_msgs
size_t max_serialized_size_key_dataglove_msgs__msg__VMG30Data(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: packet_tick
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: sensors
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rpy_hand
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: quat_hand
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rpy_forearm
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: quat_forearm
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = dataglove_msgs__msg__VMG30Data;
    is_plain =
      (
      offsetof(DataType, quat_forearm) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _VMG30Data__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const dataglove_msgs__msg__VMG30Data * ros_message = static_cast<const dataglove_msgs__msg__VMG30Data *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_dataglove_msgs__msg__VMG30Data(ros_message, cdr);
}

static bool _VMG30Data__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  dataglove_msgs__msg__VMG30Data * ros_message = static_cast<dataglove_msgs__msg__VMG30Data *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_dataglove_msgs__msg__VMG30Data(cdr, ros_message);
}

static uint32_t _VMG30Data__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dataglove_msgs__msg__VMG30Data(
      untyped_ros_message, 0));
}

static size_t _VMG30Data__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_dataglove_msgs__msg__VMG30Data(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VMG30Data = {
  "dataglove_msgs::msg",
  "VMG30Data",
  _VMG30Data__cdr_serialize,
  _VMG30Data__cdr_deserialize,
  _VMG30Data__get_serialized_size,
  _VMG30Data__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _VMG30Data__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VMG30Data,
  get_message_typesupport_handle_function,
  &dataglove_msgs__msg__VMG30Data__get_type_hash,
  &dataglove_msgs__msg__VMG30Data__get_type_description,
  &dataglove_msgs__msg__VMG30Data__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dataglove_msgs, msg, VMG30Data)() {
  return &_VMG30Data__type_support;
}

#if defined(__cplusplus)
}
#endif
