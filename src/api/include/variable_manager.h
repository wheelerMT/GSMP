/* ────────────────────────────────────────────────────────────────── *
 * FILENAME : variable_manager.h
 *
 * DESCRIPTION : Declares external functions to implement the C API to
 *               CPP Class 'VariableManager'.
 *
 * ────────────────────────────────────────────────────────────────── */

#ifndef VARIABLE_MANAGER_H
#define VARIABLE_MANAGER_H

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
#define GSMP_VISIBILITY GSMP_LINKAGE __declspec(dllexport)
#elif defined(_MSC_VER) && defined(GSMP_USE_SHARED)
// Use as a Windows Shared Library (.dll)
#define GSMP_VISIBILITY GSMP_LINKAGE __declspec(dllimport)
#elif defined(_MSC_VER) && defined(GSMP_BUILD_SHARED)
// Build as Unix Shared Library (.so)
#define GSMP_VISIBILITY GSMP_LINKAGE __attribute__((visibility("default")))
#else
// Visibility Unmodified, for Static Linkage (.lib)
#define GSMP_VISIBILITY GSMP_LINKAGE
#endif

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                           RETURN CODE                          │ */
/* └────────────────────────────────────────────────────────────────┘ */

#define GSMP_API GSMP_VISIBILITY ReturnCode

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      GSMP VARIABLE MANAGER                     │ */
/* └────────────────────────────────────────────────────────────────┘ */

#include "GSMP_enums.h"
#include "GSMP_types.h"

// Opaque pointer to GSMP Variable Manager Instance
typedef struct GSMP_Instance GSMP_Instance;

// Model Instance Management
GSMP_API GSMP_VariableManager_Create(GSMP_Instance *instance);

GSMP_API GSMP_VariableManager_Destroy(GSMP_Instance *instance);

// Model Variable Instantiation
GSMP_API GSMP_VariableManager_AddVariable_Int(GSMP_Instance *instance, string_t name, int_t value,
                                              VariableIntent intent, string_t description);
GSMP_API GSMP_VariableManager_AddVariable_Single(GSMP_Instance *instance, string_t name, single_t value,
                                                 VariableIntent intent, string_t description);
GSMP_API GSMP_VariableManager_AddVariable_Double(GSMP_Instance *instance, string_t name, double_t value,
                                                 VariableIntent intent, string_t description);

// Model Variables (Runtime)
GSMP_API GSMP_VariableManager_GetVariableType(GSMP_Instance *instance, string_t name, int_t *pValue);

GSMP_API GSMP_VariableManager_GetVariableIntent(GSMP_Instance *instance, string_t name,
                                                VariableIntent *pVariableIntent);

GSMP_API GSMP_VariableManager_GetVariableDescription(GSMP_Instance *instance, string_t name, string_t *pDescription);

GSMP_API GSMP_VariableManager_SetVariable_Int(GSMP_Instance *instance, string_t name, int_t *pValue);
GSMP_API GSMP_VariableManager_SetVariable_Single(GSMP_Instance *instance, string_t name, single_t *pValue);
GSMP_API GSMP_VariableManager_SetVariable_Double(GSMP_Instance *instance, string_t name, double_t *pValue);

GSMP_API GSMP_VariableManager_GetVariable_Int(GSMP_Instance *instance, string_t name, int_t *pValue);
GSMP_API GSMP_VariableManager_GetVariable_Single(GSMP_Instance *instance, string_t name, single_t *pValue);
GSMP_API GSMP_VariableManager_GetVariable_Double(GSMP_Instance *instance, string_t name, double_t *pValue);

#endif // VARIABLE_MANAGER_H
