/* ────────────────────────────────────────────────────────────────── *
 * FILENAME : enums.h
 *
 * DESCRIPTION : Defines all GSMP Enumerations used by:
 *               Model, VariableManager, & Variable.
 *
 *  ────────────────────────────────────────────────────────────────── */

#ifndef ENUMS_H
#define ENUMS_H

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      GSMP ENUMERATIONS                         │ */
/* └────────────────────────────────────────────────────────────────┘ */

typedef enum { UNDEFINED, INPUT, OUTPUT, OVERRIDE } VariableIntent;

typedef enum {
    DOUBLE, // double
    SINGLE, // float
    BYTE, // int8_t
    UNSIGNED_BYTE, // uint8_t
    SHORT, // int16_t
    UNSIGNED_SHORT, // uint16_t
    INT, // int32_t
    UNSIGNED_INT, // uint32_t
    LONG, // int64_t
    UNSIGNED_LONG, // uint64_t
    BOOLEAN, // bool
    STRING // char*
} VariableType;

typedef enum { OK = 0, ERROR = -1, PENDING = 1 } ReturnCode;

#endif // ENUMS_H
