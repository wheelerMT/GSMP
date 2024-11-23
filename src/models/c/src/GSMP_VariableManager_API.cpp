/* ────────────────────────────────────────────────────────────────── *
* FILENAME : GSMP_VariableManager_API.cpp
*
* DESCRIPTION : Defines Cpp functions to implement the C API to
*               CPP Class 'VariableManager'.
*
/* ────────────────────────────────────────────────────────────────── */

// C Includes
#include "GSMP_VariableManager_API.h"

// Cpp Includes
#include <iostream> // For std::cerr (debug messages)
#include <new> // For std::nothrow and std::bad_alloc
#include "variable_manager.h"


// Model Instance Management
GSMP_API GSMP_VariableManager_Create(GSMP_Instance *instance)
{
    if (instance != nullptr)
    {
        std::cerr << "[ERROR] Non-null pointer passed to GSMP_VariableManager_Create. Instance already initialized.\n";
        return ERROR; // Instance already initialized
    }

    try
    {
        instance = reinterpret_cast<GSMP_Instance *>(new VariableManager());
    } catch (const std::bad_alloc &)
    {
        std::cerr << "[ERROR] Memory allocation failed in GSMP_VariableManager_Create.\n";
        return ERROR; // Memory allocation failure
    } catch (const std::exception &ex)
    {
        std::cerr << "[ERROR] Exception caught in GSMP_VariableManager_Create: " << ex.what() << '\n';
        return ERROR; // Other standard exceptions
    } catch (...)
    {
        std::cerr << "[INFO] VariableManager instance successfully created.\n";
        return ERROR; // Catch-all for non-standard exceptions
    }

    return OK;
};

GSMP_API GSMP_VariableManager_Destroy(GSMP_Instance *instance)
{
    if (instance = nullptr)
    {
        std::cerr << "[ERROR] Null pointer passed to GSMP_VariableManager_Destroy. Cannot destroy uninitialized "
                     "instance.\n";
        return ERROR; // Instance not initialized
    }

    try
    {
        std::cerr << "[DEBUG] Deleting VariableManager instance.\n";
        delete reinterpret_cast<VariableManager *>(instance);
        instance = nullptr; // Set the pointer to null to avoid dangling pointers
    } catch (const std::exception &ex)
    {
        std::cerr << "[ERROR] Exception caught while deleting instance: " << ex.what() << '\n';
        return ERROR;
    } catch (...)
    {
        std::cerr << "[ERROR] Unknown exception caught while deleting instance.\n";
        return ERROR;
    }

    std::cerr << "[INFO] VariableManager instance successfully destroyed.\n";
    return OK;
}

// Model Variable Instantiation
// QUESTION - C to CPP types.
// QUESTION - During Instantiation, we need to copy data when instantiating new instances of objects???
// QUESTION - When runtime/querying we wish to return current state as reference or as copy ???
GSMP_API GSMP_VariableManager_AddVariable_Int(GSMP_Instance *instance, const string_t name, int_t *value,
                                              VariableIntent *intent, string_t description)
{
    if (instance = nullptr)
    {
        std::cerr << "[ERROR] Null pointer passed to GSMP_VariableManager_Destroy. Cannot destroy uninitialized "
                     "instance.\n";
        return ERROR; // Instance not initialized
    }

    // TODO Check for invalid arguments: name, intent, value, description.
    // if ()
    // {
    //     std::cerr << "[ERROR] Null name provided to GSMP_VariableManager_AddVariable_Int.\n";
    //     return ERROR;
    // }

    try
    {
        // Cast to actual implementation class
        VariableManager *variableManager = reinterpret_cast<VariableManager *>(instance);

        // TODO Cast/Intermediary Types (C to Cpp)

        // Create Variable
        // ModelVariable modelVariable = new ModelVariable(name, value, intent, description);

        // Add Variable to VariableManager instance
        std::cerr << "[DEBUG] Calling VariableManager::add_variable.\n";
        ReturnCode returnCode = variableManager->add_variable(modelVariable);

    } catch (const std::exception &ex)
    {
        std::cerr << "[ERROR] Exception caught in GSMP_VariableManager_AddVariable_Int: " << ex.what() << '\n';
        return ERROR;
    } catch (...)
    {
        std::cerr << "[ERROR] Unknown exception caught in GSMP_VariableManager_AddVariable_Int.\n";
        return ERROR;
    }

    std::cerr << "[INFO] GSMP_VariableManager_AddVariable_Int completed successfully.\n";
    return OK;
}
GSMP_API GSMP_VariableManager_AddVariable_Single(GSMP_Instance *instance, string_t name, int_t *value,
                                                 VariableIntent *intent, string_t description);
GSMP_API GSMP_VariableManager_AddVariable_Double(GSMP_Instance *instance, string_t name, int_t *value,
                                                 VariableIntent *intent, string_t description);

// Model Variables (Runtime)
GSMP_API GSMP_VariableManager_GetVariableType(GSMP_Instance *instance, string_t name, int_t *value);

GSMP_API GSMP_VariableManager_GetVariableIntent(GSMP_Instance *instance, string_t name, VariableIntent *variableIntent);

GSMP_API GSMP_VariableManager_GetVariableDescription(GSMP_Instance *instance, string_t name, int_t *value);

GSMP_API GSMP_VariableManager_SetVariable_Int(GSMP_Instance *instance, string_t name, int_t *value);
GSMP_API GSMP_VariableManager_SetVariable_Single(GSMP_Instance *instance, string_t name, single_t *value);
GSMP_API GSMP_VariableManager_SetVariable_Double(GSMP_Instance *instance, string_t name, double_t *value);

GSMP_API GSMP_VariableManager_GetVariable_Int(GSMP_Instance *instance, string_t name, int_t *value);
GSMP_API GSMP_VariableManager_GetVariable_Single(GSMP_Instance *instance, string_t name, single_t *value);
GSMP_API GSMP_VariableManager_GetVariable_Double(GSMP_Instance *instance, string_t name, double_t *value);