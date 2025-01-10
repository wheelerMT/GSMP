/* ────────────────────────────────────────────────────────────────── *
 * FILENAME : model_api.h
 *
 * DESCRIPTION : Declares external functions to implement the C API to
 *               CPP Class 'Model'.
 *
 * ────────────────────────────────────────────────────────────────── */

#ifndef MODEL_H
#define MODEL_H

#include "linkage.h"

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                           GSMP MODEL                           │ */
/* └────────────────────────────────────────────────────────────────┘ */

// Opaque pointer to GSMP Model Instance
typedef struct GSMP_Instance GSMP_Instance;

// Model Instance Management
GSMP_API Model_Create(GSMP_Instance *instance);

GSMP_API Model_Destroy(GSMP_Instance *instance);

// Model Runtime
GSMP_API Model_Initialize(GSMP_Instance *instance);

GSMP_API Model_Reinitialize(GSMP_Instance *instance);

GSMP_API Model_Step(GSMP_Instance *instance);

GSMP_API Model_Terminate(GSMP_Instance *instance);

// Model Variables
GSMP_API Model_GetVariableType(GSMP_Instance *instance, char *name, int *value);

GSMP_API Model_GetVariableDescription(GSMP_Instance *instance, char *name, int *value);

GSMP_API Model_SetVariable_Int(GSMP_Instance *instance, char *name, int *value);

GSMP_API Model_SetVariable_Float(GSMP_Instance *instance, char *name, float *value);

GSMP_API Model_SetVariable_Double(GSMP_Instance *instance, char *name, double *value);

GSMP_API Model_GetVariable_Int(GSMP_Instance *instance, char *name, int *value);

GSMP_API Model_GetVariable_Float(GSMP_Instance *instance, char *name, float *value);

GSMP_API Model_GetVariable_Double(GSMP_Instance *instance, char *name, double *value);

// ... TODO: GSMP Supported Types //
// ... TODO: GSMP Supported Arrays //

#endif // MODEL_H
