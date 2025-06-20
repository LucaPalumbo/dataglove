// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice
#include "dataglove_msgs/msg/detail/vmg30_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sensors`
// Member `rpy_hand`
// Member `quat_hand`
// Member `rpy_forearm`
// Member `quat_forearm`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
dataglove_msgs__msg__VMG30Data__init(dataglove_msgs__msg__VMG30Data * msg)
{
  if (!msg) {
    return false;
  }
  // sensors
  if (!rosidl_runtime_c__float__Sequence__init(&msg->sensors, 0)) {
    dataglove_msgs__msg__VMG30Data__fini(msg);
    return false;
  }
  // rpy_hand
  if (!rosidl_runtime_c__float__Sequence__init(&msg->rpy_hand, 0)) {
    dataglove_msgs__msg__VMG30Data__fini(msg);
    return false;
  }
  // quat_hand
  if (!rosidl_runtime_c__float__Sequence__init(&msg->quat_hand, 0)) {
    dataglove_msgs__msg__VMG30Data__fini(msg);
    return false;
  }
  // rpy_forearm
  if (!rosidl_runtime_c__float__Sequence__init(&msg->rpy_forearm, 0)) {
    dataglove_msgs__msg__VMG30Data__fini(msg);
    return false;
  }
  // quat_forearm
  if (!rosidl_runtime_c__float__Sequence__init(&msg->quat_forearm, 0)) {
    dataglove_msgs__msg__VMG30Data__fini(msg);
    return false;
  }
  return true;
}

void
dataglove_msgs__msg__VMG30Data__fini(dataglove_msgs__msg__VMG30Data * msg)
{
  if (!msg) {
    return;
  }
  // sensors
  rosidl_runtime_c__float__Sequence__fini(&msg->sensors);
  // rpy_hand
  rosidl_runtime_c__float__Sequence__fini(&msg->rpy_hand);
  // quat_hand
  rosidl_runtime_c__float__Sequence__fini(&msg->quat_hand);
  // rpy_forearm
  rosidl_runtime_c__float__Sequence__fini(&msg->rpy_forearm);
  // quat_forearm
  rosidl_runtime_c__float__Sequence__fini(&msg->quat_forearm);
}

bool
dataglove_msgs__msg__VMG30Data__are_equal(const dataglove_msgs__msg__VMG30Data * lhs, const dataglove_msgs__msg__VMG30Data * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sensors
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->sensors), &(rhs->sensors)))
  {
    return false;
  }
  // rpy_hand
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->rpy_hand), &(rhs->rpy_hand)))
  {
    return false;
  }
  // quat_hand
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->quat_hand), &(rhs->quat_hand)))
  {
    return false;
  }
  // rpy_forearm
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->rpy_forearm), &(rhs->rpy_forearm)))
  {
    return false;
  }
  // quat_forearm
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->quat_forearm), &(rhs->quat_forearm)))
  {
    return false;
  }
  return true;
}

bool
dataglove_msgs__msg__VMG30Data__copy(
  const dataglove_msgs__msg__VMG30Data * input,
  dataglove_msgs__msg__VMG30Data * output)
{
  if (!input || !output) {
    return false;
  }
  // sensors
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->sensors), &(output->sensors)))
  {
    return false;
  }
  // rpy_hand
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->rpy_hand), &(output->rpy_hand)))
  {
    return false;
  }
  // quat_hand
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->quat_hand), &(output->quat_hand)))
  {
    return false;
  }
  // rpy_forearm
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->rpy_forearm), &(output->rpy_forearm)))
  {
    return false;
  }
  // quat_forearm
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->quat_forearm), &(output->quat_forearm)))
  {
    return false;
  }
  return true;
}

dataglove_msgs__msg__VMG30Data *
dataglove_msgs__msg__VMG30Data__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dataglove_msgs__msg__VMG30Data * msg = (dataglove_msgs__msg__VMG30Data *)allocator.allocate(sizeof(dataglove_msgs__msg__VMG30Data), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dataglove_msgs__msg__VMG30Data));
  bool success = dataglove_msgs__msg__VMG30Data__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dataglove_msgs__msg__VMG30Data__destroy(dataglove_msgs__msg__VMG30Data * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dataglove_msgs__msg__VMG30Data__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dataglove_msgs__msg__VMG30Data__Sequence__init(dataglove_msgs__msg__VMG30Data__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dataglove_msgs__msg__VMG30Data * data = NULL;

  if (size) {
    data = (dataglove_msgs__msg__VMG30Data *)allocator.zero_allocate(size, sizeof(dataglove_msgs__msg__VMG30Data), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dataglove_msgs__msg__VMG30Data__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dataglove_msgs__msg__VMG30Data__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dataglove_msgs__msg__VMG30Data__Sequence__fini(dataglove_msgs__msg__VMG30Data__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dataglove_msgs__msg__VMG30Data__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dataglove_msgs__msg__VMG30Data__Sequence *
dataglove_msgs__msg__VMG30Data__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dataglove_msgs__msg__VMG30Data__Sequence * array = (dataglove_msgs__msg__VMG30Data__Sequence *)allocator.allocate(sizeof(dataglove_msgs__msg__VMG30Data__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dataglove_msgs__msg__VMG30Data__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dataglove_msgs__msg__VMG30Data__Sequence__destroy(dataglove_msgs__msg__VMG30Data__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dataglove_msgs__msg__VMG30Data__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dataglove_msgs__msg__VMG30Data__Sequence__are_equal(const dataglove_msgs__msg__VMG30Data__Sequence * lhs, const dataglove_msgs__msg__VMG30Data__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dataglove_msgs__msg__VMG30Data__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dataglove_msgs__msg__VMG30Data__Sequence__copy(
  const dataglove_msgs__msg__VMG30Data__Sequence * input,
  dataglove_msgs__msg__VMG30Data__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dataglove_msgs__msg__VMG30Data);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dataglove_msgs__msg__VMG30Data * data =
      (dataglove_msgs__msg__VMG30Data *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dataglove_msgs__msg__VMG30Data__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dataglove_msgs__msg__VMG30Data__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dataglove_msgs__msg__VMG30Data__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
