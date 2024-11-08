/* ────────────────────────────────────────────────────────────────── *
* FILENAME : GSMP_VariableManager_API.h
*
* DESCRIPTION : Declares external functions to implement the C API to
*               CPP Class 'Model'.
*
/* ────────────────────────────────────────────────────────────────── */

#ifndef GSMP_VARIABLE_MANAGER_API_H
#define GSMP_VARIABLE_MANAGER_API_H

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                            LINKAGE                             │ */
/* └────────────────────────────────────────────────────────────────┘ */

#if defined(__cplusplus)
#define GSMP_LINKAGE extern 'C'
#else
#define GSMP_LINKAGE extern
#endif

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                          VISIBILITY                            │ */
/* └────────────────────────────────────────────────────────────────┘ */

#if defined(_MSC_VER) && defined(GSMP_BUILD_SHARED)
// Build as Windows Shared Library (.dll)
#define GSMP_API GSMP_LINKAGE __declspec(dllexport)
#elif defined(_MSC_VER) && defined(GSMP_USE_SHARED)
// Use as a Windows Shared Library (.dll)
#define GSMP_API GSMP_LINKAGE __declspec(dllimport)
#elif defined(_MSC_VER) && defined(GSMP_BUILD_SHARED)
// Build as Unix Shared Library (.so)
#define GSMP_API GSMP_LINKAGE __attribute__((visibility("default")))
#else
// Visibility Unmodified, for Static Linkage (.lib)
#define GSMP_API GSMP_LINKAGE
#endif

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                           GSMP MODEL                           │ */
/* └────────────────────────────────────────────────────────────────┘ */

#include "GSMP_model_types.h"

// Opaque pointer to GSMP Variable Manager Instance
typedef struct GSMP_Instance GSMP_Instance;

// Model Instance Management
GSMP_API int GSMP_Variable_Manager_Create(GSMP_Instance *instance);

GSMP_API int GSMP_Variable_Manager_Destroy(GSMP_Instance *instance);

// Model Variable Instantiation


// Model Variables (Runtime)
GSMP_API int GSMP_Variable_Manager_GetVariableType(GSMP_Instance *instance, char *name, int *value);

GSMP_API int GSMP_Variable_Manager_GetVariableDescription(GSMP_Instance *instance, char *name, int *value);

GSMP_API int GSMP_Variable_Manager_SetVariable_Int(GSMP_Instance *instance, char *name, int *value);

GSMP_API int GSMP_Variable_Manager_SetVariable_Float(GSMP_Instance *instance, char *name, float *value);

GSMP_API int GSMP_Variable_Manager_SetVariable_Double(GSMP_Instance *instance, char *name, double *value);

GSMP_API int GSMP_Variable_Manager_GetVariable_Int(GSMP_Instance *instance, char *name, int *value);

GSMP_API int GSMP_Variable_Manager_GetVariable_Float(GSMP_Instance *instance, char *name, float *value);

GSMP_API int GSMP_Variable_Manager_GetVariable_Double(GSMP_Instance *instance, char *name, double *value);

// ... TODO: GSMP Supported Types //
// ... TODO: GSMP Supported Arrays //

#endif // GSMP_VARIABLE_MANAGER_API_H
