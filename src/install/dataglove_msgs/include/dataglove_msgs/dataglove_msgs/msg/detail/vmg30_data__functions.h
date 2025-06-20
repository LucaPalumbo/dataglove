// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dataglove_msgs:msg/VMG30Data.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "dataglove_msgs/msg/vmg30_data.h"


#ifndef DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__FUNCTIONS_H_
#define DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "dataglove_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "dataglove_msgs/msg/detail/vmg30_data__struct.h"

/// Initialize msg/VMG30Data message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dataglove_msgs__msg__VMG30Data
 * )) before or use
 * dataglove_msgs__msg__VMG30Data__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
bool
dataglove_msgs__msg__VMG30Data__init(dataglove_msgs__msg__VMG30Data * msg);

/// Finalize msg/VMG30Data message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
void
dataglove_msgs__msg__VMG30Data__fini(dataglove_msgs__msg__VMG30Data * msg);

/// Create msg/VMG30Data message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dataglove_msgs__msg__VMG30Data__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
dataglove_msgs__msg__VMG30Data *
dataglove_msgs__msg__VMG30Data__create(void);

/// Destroy msg/VMG30Data message.
/**
 * It calls
 * dataglove_msgs__msg__VMG30Data__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
void
dataglove_msgs__msg__VMG30Data__destroy(dataglove_msgs__msg__VMG30Data * msg);

/// Check for msg/VMG30Data message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
bool
dataglove_msgs__msg__VMG30Data__are_equal(const dataglove_msgs__msg__VMG30Data * lhs, const dataglove_msgs__msg__VMG30Data * rhs);

/// Copy a msg/VMG30Data message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
bool
dataglove_msgs__msg__VMG30Data__copy(
  const dataglove_msgs__msg__VMG30Data * input,
  dataglove_msgs__msg__VMG30Data * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
const rosidl_type_hash_t *
dataglove_msgs__msg__VMG30Data__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
const rosidl_runtime_c__type_description__TypeDescription *
dataglove_msgs__msg__VMG30Data__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
const rosidl_runtime_c__type_description__TypeSource *
dataglove_msgs__msg__VMG30Data__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
dataglove_msgs__msg__VMG30Data__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/VMG30Data messages.
/**
 * It allocates the memory for the number of elements and calls
 * dataglove_msgs__msg__VMG30Data__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
bool
dataglove_msgs__msg__VMG30Data__Sequence__init(dataglove_msgs__msg__VMG30Data__Sequence * array, size_t size);

/// Finalize array of msg/VMG30Data messages.
/**
 * It calls
 * dataglove_msgs__msg__VMG30Data__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
void
dataglove_msgs__msg__VMG30Data__Sequence__fini(dataglove_msgs__msg__VMG30Data__Sequence * array);

/// Create array of msg/VMG30Data messages.
/**
 * It allocates the memory for the array and calls
 * dataglove_msgs__msg__VMG30Data__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
dataglove_msgs__msg__VMG30Data__Sequence *
dataglove_msgs__msg__VMG30Data__Sequence__create(size_t size);

/// Destroy array of msg/VMG30Data messages.
/**
 * It calls
 * dataglove_msgs__msg__VMG30Data__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
void
dataglove_msgs__msg__VMG30Data__Sequence__destroy(dataglove_msgs__msg__VMG30Data__Sequence * array);

/// Check for msg/VMG30Data message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
bool
dataglove_msgs__msg__VMG30Data__Sequence__are_equal(const dataglove_msgs__msg__VMG30Data__Sequence * lhs, const dataglove_msgs__msg__VMG30Data__Sequence * rhs);

/// Copy an array of msg/VMG30Data messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dataglove_msgs
bool
dataglove_msgs__msg__VMG30Data__Sequence__copy(
  const dataglove_msgs__msg__VMG30Data__Sequence * input,
  dataglove_msgs__msg__VMG30Data__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DATAGLOVE_MSGS__MSG__DETAIL__VMG30_DATA__FUNCTIONS_H_
