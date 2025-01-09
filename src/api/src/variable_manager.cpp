/* ────────────────────────────────────────────────────────────────── *
* FILENAME : variable_manager.cpp
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
    // TODO How to handle NULL vs nullptr https://devblogs.microsoft.com/oldnewthing/20180307-00/?p=98175
    // TODO Utility:ErrorNot_NULL/ErrorNot_nullptr
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
        // TODO Utility:ErrorMessage e.g. int ErrorMessage(returnCode, const char*) - which always returns 'ERROR' or a
        // more specific 'ERROR' code.
        std::cerr << "[ERROR] Memory allocation failed in GSMP_VariableManager_Create.\n";
        return ERROR; // Memory allocation failure
    } catch (const std::exception &ex)
    {
        std::cerr << "[ERROR] Exception caught in GSMP_VariableManager_Create: " << ex.what() << '\n';
        return ERROR;
    } catch (...)
    {
        std::cerr << "[ERROR] Failed in GSMP_VariableManager_Create.\n";
        return ERROR;
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
        delete reinterpret_cast<VariableManager *>(instance);
        instance = nullptr; // TODO NULL vs nullptr
    } catch (const std::exception &ex)
    {
        std::cerr << "[ERROR] Exception caught in GSMP_VariableManager_Destroy while deleting instance: " << ex.what()
                  << '\n';
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
GSMP_API GSMP_VariableManager_AddVariable_Int(GSMP_Instance *instance, const string_t name, const int_t value,
                                              VariableIntent intent, const string_t description)
{
    if (instance = nullptr)
    {
        std::cerr << "[ERROR] Null pointer passed to GSMP_VariableManager_AddVariable_Int. Cannot destroy "
                     "uninitialized instance.\n";
        return ERROR; // Instance not initialized
    }
    // TODO Check for invalid arguments: name, intent, value, description, or just catch associated exceptions.

    try
    {
        // Cast to actual implementation class
        VariableManager *variableManager = reinterpret_cast<VariableManager *>(instance);

        // Intermediary Types (C to Cpp)
        std::string cppName = name;
        std::string cppDescription = description;

        // ISSUE: GSMP-17 - Require intent to be compatible.
        ModelVariableIntent cppIntent = ModelVariableIntent::Undefined;
        switch (intent)
        {
            case VariableIntent::INPUT:
                cppIntent = ModelVariableIntent::Input;
                break;
            case VariableIntent::OUTPUT:
                cppIntent = ModelVariableIntent::Output;
                break;
            case VariableIntent::OVERRIDE:
                cppIntent = ModelVariableIntent::Override;
                break;
            default:
                std::cerr
                        << "[ERROR] Null pointer passed to GSMP_VariableManager_Destroy. Cannot destroy uninitialized "
                           "instance.\n";
                break;
        }
        ModelVariableIntent cppIntent = ModelVariableIntent::Input;

        // Create Variable
        // ISSUE: GSMP-17 : Check constructor assignment shallow or deep copy.
        ModelVariable *modelVariable = new ModelVariable(cppName, value, cppIntent, cppDescription);

        // Add Variable to VariableManager instance
        variableManager->add_variable(*modelVariable);

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
GSMP_API GSMP_VariableManager_AddVariable_Single(GSMP_Instance *instance, const string_t name, const single_t value,
                                                 VariableIntent intent, const string_t description);
GSMP_API GSMP_VariableManager_AddVariable_Double(GSMP_Instance *instance, const string_t name, const double_t value,
                                                 VariableIntent intent, const string_t description);

// Model Variables (Runtime)
GSMP_API GSMP_VariableManager_GetVariableType(GSMP_Instance *instance, const string_t name, int_t *pValue);

GSMP_API GSMP_VariableManager_GetVariableIntent(GSMP_Instance *instance, const string_t name,
                                                VariableIntent *pVariableIntent);

GSMP_API GSMP_VariableManager_GetVariableDescription(GSMP_Instance *instance, const string_t name,
                                                     string_t *pDescription);

GSMP_API GSMP_VariableManager_SetVariable_Int(GSMP_Instance *instance, const string_t name, int_t *pValue);
GSMP_API GSMP_VariableManager_SetVariable_Single(GSMP_Instance *instance, const string_t name, single_t *pValue);
GSMP_API GSMP_VariableManager_SetVariable_Double(GSMP_Instance *instance, const string_t name, double_t *pValue);

GSMP_API GSMP_VariableManager_GetVariable_Int(GSMP_Instance *instance, const string_t name, int_t *pValue);
GSMP_API GSMP_VariableManager_GetVariable_Single(GSMP_Instance *instance, const string_t name, single_t *pValue);
GSMP_API GSMP_VariableManager_GetVariable_Double(GSMP_Instance *instance, const string_t name, double_t *pValue);
