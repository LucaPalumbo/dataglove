// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

#include "dataglove_msgs/msg/detail/vmg30_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
const rosidl_type_hash_t *
dataglove_msgs__msg__VMG30Data__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xed, 0x4c, 0x69, 0xf5, 0x02, 0x41, 0xd3, 0x6b,
      0x49, 0x2f, 0xc6, 0x26, 0x0e, 0x33, 0x7c, 0xf5,
      0x08, 0x77, 0xb1, 0xe9, 0x9d, 0x24, 0xff, 0xbd,
      0x2f, 0xbe, 0xd3, 0xce, 0xa2, 0xc9, 0x4d, 0xf5,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char dataglove_msgs__msg__VMG30Data__TYPE_NAME[] = "dataglove_msgs/msg/VMG30Data";

// Define type names, field names, and default values
static char dataglove_msgs__msg__VMG30Data__FIELD_NAME__packet_tick[] = "packet_tick";
static char dataglove_msgs__msg__VMG30Data__FIELD_NAME__time[] = "time";
static char dataglove_msgs__msg__VMG30Data__FIELD_NAME__sensors[] = "sensors";
static char dataglove_msgs__msg__VMG30Data__FIELD_NAME__rpy_hand[] = "rpy_hand";
static char dataglove_msgs__msg__VMG30Data__FIELD_NAME__quat_hand[] = "quat_hand";
static char dataglove_msgs__msg__VMG30Data__FIELD_NAME__rpy_forearm[] = "rpy_forearm";
static char dataglove_msgs__msg__VMG30Data__FIELD_NAME__quat_forearm[] = "quat_forearm";

static rosidl_runtime_c__type_description__Field dataglove_msgs__msg__VMG30Data__FIELDS[] = {
  {
    {dataglove_msgs__msg__VMG30Data__FIELD_NAME__packet_tick, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dataglove_msgs__msg__VMG30Data__FIELD_NAME__time, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dataglove_msgs__msg__VMG30Data__FIELD_NAME__sensors, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dataglove_msgs__msg__VMG30Data__FIELD_NAME__rpy_hand, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dataglove_msgs__msg__VMG30Data__FIELD_NAME__quat_hand, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dataglove_msgs__msg__VMG30Data__FIELD_NAME__rpy_forearm, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {dataglove_msgs__msg__VMG30Data__FIELD_NAME__quat_forearm, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
dataglove_msgs__msg__VMG30Data__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {dataglove_msgs__msg__VMG30Data__TYPE_NAME, 28, 28},
      {dataglove_msgs__msg__VMG30Data__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 \\t  packet_tick  # 1 value\n"
  "float32   time         # 1 value\n"
  "float32[] sensors      # 16 values\n"
  "float32[] rpy_hand     # 3 values (roll, pitch, yaw)\n"
  "float32[] quat_hand    # 4 values (w, x, y, z)\n"
  "float32[] rpy_forearm  # 3 values\n"
  "float32[] quat_forearm # 4 values";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
dataglove_msgs__msg__VMG30Data__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {dataglove_msgs__msg__VMG30Data__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 268, 268},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
dataglove_msgs__msg__VMG30Data__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *dataglove_msgs__msg__VMG30Data__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
