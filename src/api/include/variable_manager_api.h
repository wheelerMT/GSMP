/* ────────────────────────────────────────────────────────────────── *
 * FILENAME : variable_manager_api.h
 *
 * DESCRIPTION : Declares external functions to implement the C API to
 *               CPP Class 'VariableManager'.
 *
 * ────────────────────────────────────────────────────────────────── */

#ifndef VARIABLE_MANAGER_H
#define VARIABLE_MANAGER_H

#include "linkage.h"
#include "types.h"

// Opaque pointer to GSMP Variable Manager Instance
typedef struct GSMP_Instance GSMP_Instance;

// Model Instance Management
GSMP_API VariableManager_Create(GSMP_Instance *instance);

GSMP_API VariableManager_Destroy(GSMP_Instance *instance);

// Model Variable Instantiation
GSMP_API VariableManager_AddVariable_Int(GSMP_Instance *instance, string_t name, int_t value, VariableIntent intent,
                                         string_t description);
GSMP_API VariableManager_AddVariable_Single(GSMP_Instance *instance, string_t name, single_t value,
                                            VariableIntent intent, string_t description);
GSMP_API VariableManager_AddVariable_Double(GSMP_Instance *instance, string_t name, double_t value,
                                            VariableIntent intent, string_t description);

// Model Variables (Runtime)
GSMP_API VariableManager_GetVariableType(GSMP_Instance *instance, string_t name, int_t *pValue);

GSMP_API VariableManager_GetVariableIntent(GSMP_Instance *instance, string_t name, VariableIntent *pVariableIntent);

GSMP_API VariableManager_GetVariableDescription(GSMP_Instance *instance, string_t name, string_t *pDescription);

GSMP_API VariableManager_SetVariable_Int(GSMP_Instance *instance, string_t name, int_t *pValue);
GSMP_API VariableManager_SetVariable_Single(GSMP_Instance *instance, string_t name, single_t *pValue);
GSMP_API VariableManager_SetVariable_Double(GSMP_Instance *instance, string_t name, double_t *pValue);

GSMP_API VariableManager_GetVariable_Int(GSMP_Instance *instance, string_t name, int_t *pValue);
GSMP_API VariableManager_GetVariable_Single(GSMP_Instance *instance, string_t name, single_t *pValue);
GSMP_API VariableManager_GetVariable_Double(GSMP_Instance *instance, string_t name, double_t *pValue);

#endif // VARIABLE_MANAGER_H
