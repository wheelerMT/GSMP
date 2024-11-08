/* ────────────────────────────────────────────────────────────────── *
* FILENAME : GSMP_model_types.h
*
* DESCRIPTION : Declares all common GSMP Model types.
*
/* ────────────────────────────────────────────────────────────────── */

#ifndef GSMP_MODEL_TYPES_H
#define GSMP_MODEL_TYPES_H

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      GSMP ENUMERATIONS                         │ */
/* └────────────────────────────────────────────────────────────────┘ */

enum VariableIntent { UNDEFINED, INPUT, OUTPUT, OVERRIDE };

enum VariableType {
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
};

enum ReturnCode { OK = 0, ERROR = -1, PENDING = 1 };

#endif // GSMP_MODEL_TYPES_H
