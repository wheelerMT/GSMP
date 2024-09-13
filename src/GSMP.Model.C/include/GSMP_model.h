/* ────────────────────────────────────────────────────────────────── *
* FILENAME : GSMP_model.h
*
* DESCRIPTION : Declares external functions to implement the Model
*               Interface.
*
/* ────────────────────────────────────────────────────────────────── */

#ifndef GSMP_MODEL_H
#define	GSMP_MODEL_H

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
#define GSMP_API GSMP_LINKAGE __attribute__((visbility("default")))
#else
// Visibility Unmodified, for Static Linkage (.lib)
#define GSMP_API GSMP_LINKAGE
#endif

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                           GSMP MODEL                           │ */
/* └────────────────────────────────────────────────────────────────┘ */

#include "GSMP_ModelTypes.h"

// Opaque pointer to GSMP Model Instance
typedef struct GSMPModel GSMPModel;

// Model Instance Management
GSMP_API int GSMP_Model_Create(GSMPModel* model);
GSMP_API int GSMP_Model_Destroy(GSMPModel* model);

// Model Runtime
GSMP_API int GSMP_Model_Initialize(GSMPModel* model);
GSMP_API int GSMP_Model_Reinitialize(GSMPModel* model);
GSMP_API int GSMP_Model_Step(GSMPModel* model);
GSMP_API int GSMP_Model_Terminate(GSMPModel* model);

// Model Variables
GSMP_API int GSMP_Model_GetVariableType(GSMPModel* model, char* name, int* value);
GSMP_API int GSMP_Model_GetVariableDescription(GSMPModel* model, char* name, int* value);

GSMP_API int GSMP_Model_SetVariable_Int(GSMPModel* model, char* name, int* value);
GSMP_API int GSMP_Model_SetVariable_Float(GSMPModel* model, char* name, float* value);
GSMP_API int GSMP_Model_SetVariable_Double(GSMPModel* model, char* name, double* value);

GSMP_API int GSMP_Model_GetVariable_Int(GSMPModel* model, char* name, int* value);
GSMP_API int GSMP_Model_GetVariable_Float(GSMPModel* model, char* name, float* value);
GSMP_API int GSMP_Model_GetVariable_Double(GSMPModel* model, char* name, double* value);

// ... TODO: GSMP Supported Types //
// ... TODO: GSMP Supported Arrays //

#endif // !GSMP_MODEL_H

