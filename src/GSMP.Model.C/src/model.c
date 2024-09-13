/* ────────────────────────────────────────────────────────────────── *
* FILENAME : model.c
*
* DESCRIPTION : Defines external functions to implement the Model
*               Interface for this specific Model.
*
/* ────────────────────────────────────────────────────────────────── */

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                           GSMP MODEL                           │ */
/* └────────────────────────────────────────────────────────────────┘ */

#include "GSMP_model.h"
#include "GSMP_model_types.h"

// TODO: How to reference into this style of structure. For example
//       to find name 'iInt'. Might have to consider an alternative
//       that's an array.
typedef struct GSMP_Inputs {
    GSMP_Variable_t iInt;
    GSMP_Variable_t iFloat;
    GSMP_Variable_t iDouble;
} GSMPInputs_t;

typedef struct GSMPOutputs {
    GSMP_Variable_t oInt;
    GSMP_Variable_t oFloat;
    GSMP_Variable_t oDouble;
} GSMPOutputs_t;

typedef struct GSMPModel {
    double time;
    double timeStep;

    GSMPInputs_t Inputs;
    GSMPOutputs_t Outputs;
} GSMPModel_t;

/* ────────────────────────────────────────────────────────────────── */
// Model Instance Management
/* ────────────────────────────────────────────────────────────────── */

GSMP_API int GSMP_Model_Create(GSMPModel* model)
{
    // TOOD: Create Model Instance (Memory Allocation)
    // TODO: Setup all Model Variable Data (use struct declaration)

    return 0;
}

GSMP_API int GSMP_Model_Destroy(GSMPModel* model)
{
    // TODO: Clear Model Variables, as applicable
    // TODO: Clear Model Instance

    return 0;
}

/* ────────────────────────────────────────────────────────────────── */
// Model Runtime
/* ────────────────────────────────────────────────────────────────── */

GSMP_API int GSMP_Model_Initialize(GSMPModel* model)
{
    return 0;
}

GSMP_API int GSMP_Model_Reinitialize(GSMPModel* model)
{
    // Reset all variables to default value
    return 0;
}

GSMP_API int GSMP_Model_Step(GSMPModel* model)
{
    // TODO: Increment Internal Time
    // TODO: Update Outputs based on Inputs
    return 0;
}

GSMP_API int GSMP_Model_Terminate(GSMPModel* model)
{
    // Close file streams etc. N/A for ExampleModel
    return 0;
}

/* ────────────────────────────────────────────────────────────────── */
// Model Variables
/* ────────────────────────────────────────────────────────────────── */

GSMP_API int GSMP_Model_GetVariableType(GSMPModel* model, char* name, int* value)
{
    // TODO: How to find the variable/property associated with the 'name'.
    //       (1) Switch on 'name', have specific types of variable struct.
    //       (2) Use void* variable, and have an array, that we search.
    //           More generic, less safe.
    //       (3) ... ideas?
    return 0;
}

GSMP_API int GSMP_Model_GetVariableDescription(GSMPModel* model, char* name, int* value)
{
    // See GSMP_Model_GetVariableType
    return 0;
}

GSMP_API int GSMP_Model_SetVariable_Int(GSMPModel* model, char* name, int* value)
{
    return 0;
}

GSMP_API int GSMP_Model_SetVariable_Float(GSMPModel* model, char* name, float* value)
{
    return 0;
}

GSMP_API int GSMP_Model_SetVariable_Double(GSMPModel* model, char* name, double* value)
{
    return 0;
}

GSMP_API int GSMP_Model_GetVariable_Int(GSMPModel* model, char* name, int* value)
{
    return 0;
}

GSMP_API int GSMP_Model_GetVariable_Float(GSMPModel* model, char* name, float* value)
{
    return 0;
}

GSMP_API int GSMP_Model_GetVariable_Double(GSMPModel* model, char* name, double* value)
{
    return 0;
}
