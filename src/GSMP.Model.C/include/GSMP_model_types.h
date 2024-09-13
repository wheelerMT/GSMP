/* ────────────────────────────────────────────────────────────────── *
* FILENAME : GSMP_model_types.h
*
* DESCRIPTION : Declares all common GSMP Model types.
*
/* ────────────────────────────────────────────────────────────────── */

#ifndef GSMP_MODEL_TYPES_H
#define	GSMP_MODEL_TYPES_H

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      GSMP MODEL ENUMERATIONS                   │ */
/* └────────────────────────────────────────────────────────────────┘ */

enum GSMP_VariableType {
    GSMP_Int = 1,
    GSMP_Float = 2,
    GSMP_Double = 3
};

// TODO: Implement Return Codes
enum GSMP_Return {
    GSMP_OK = 0,
    GSMP_ERROR = -1,
    GSMP_PENDING = 1
};

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                     GSMP MODEL VARIABLE TYPES                  │ */
/* └────────────────────────────────────────────────────────────────┘ */

typedef struct GSMP_Variable {
    char *name;
    enum GSMP_VariableType type;
    char *description;
    void *pValue;
} GSMP_Variable_t;

// TODO: Switch to type specific versions vs generic.

#endif // GSMP_MODEL_TYPES_H
