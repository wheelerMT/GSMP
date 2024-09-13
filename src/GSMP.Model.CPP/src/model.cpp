#include "model.h"
#include "GSMP_model_types.h"

Model::Model()
{
    initialise();
}

Model::~Model()
{
    terminate();
}

void Model::AddVariable(const GSMP_Variable &variable)
{
    variables.push_back(variable);
}

void Model::initialise()
{
    // Create a set of inputs
    for (int i = 0; i < 3; ++i)
    {
        variables.push_back(createVariable(static_cast<GSMP_VariableType>(i), GSMP_VariableIntent::Input));
    }

    // Create a set of outputs
    for (int i = 0; i < 3; ++i)
    {
        variables.push_back(createVariable(static_cast<GSMP_VariableType>(i), GSMP_VariableIntent::Output));
    }
}

void Model::reinitialise()
{
    variables.clear();
    initialise();
}

void Model::step() const
{
    for (auto variable: variables)
    {
        if (variable.intent == GSMP_VariableIntent::Output)
        {
            switch (variable.type)
            {
                case GSMP_VariableType::Int:
                    variable.value = std::get<int>(variable.value) + 1;
                    break;
                case GSMP_VariableType::Float:
                    variable.value = std::get<float>(variable.value) + 1.0f;
                    break;
                case GSMP_VariableType::Double:
                    variable.value = std::get<double>(variable.value) + 1.0;
                    break;
            }
        }
    }
}

void Model::terminate()
{
    variables.clear();
}

GSMP_Variable Model::createVariable(GSMP_VariableType type, GSMP_VariableIntent intent)
{
    // Determine default value based on type
    std::string name;
    std::variant<int, float, double> value;
    switch (type)
    {
        case GSMP_VariableType::Int:
            value = 1;
            name = "int";
            break;
        case GSMP_VariableType::Float:
            value = 1.0f;
            name = "float";
            break;
        case GSMP_VariableType::Double:
            value = 1.0;
            name = "double";
            break;
        default:
            value = 1;
    }

    // Determine prefix based on intent
    std::string prefix;
    switch (intent)
    {
        case GSMP_VariableIntent::Input:
            prefix = "i_";
            break;
        case GSMP_VariableIntent::Output:
            prefix = "o_";
            break;
        default: prefix = "undef_";
    }
    name = prefix + name;

    // Construct GSMP_VariableType
    return {name, type, value, intent};
}
