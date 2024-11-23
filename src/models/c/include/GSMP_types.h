/* ────────────────────────────────────────────────────────────────── *
 * FILENAME : GSMP_types.h
 *
 * DESCRIPTION : Defines all GSMP Types used by:
 *               Model, VariableManager, & Variable.
 *
 *  ────────────────────────────────────────────────────────────────── */

#ifndef GSMP_TYPES_H
#define GSMP_TYPES_H

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                         GSMP TYPES                             │ */
/* └────────────────────────────────────────────────────────────────┘ */

#include <stdint.h>

// QUESTION: Use alias name style that is common to all our types that are enumerated?
typedef double double_t;
typedef float single_t;
typedef int8_t byte_t;
typedef uint8_t unsigned_byte_t;
typedef int16_t short_t;
typedef uint16_t unsigned_short_t;
typedef int32_t int_t;
typedef uint32_t unsigned_int_t;
typedef int64_t long_t;
typedef uint64_t unsigned_long_t;
typedef bool boolean_t;
typedef char *string_t;

// NULL for C, or use <stdlib. h>. For Cpp use nullptr.
#define NULL ((void *) 0)

#endif // GSMP_TYPES_H
