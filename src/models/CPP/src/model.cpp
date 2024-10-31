#include "model.h"
#include "model_types.h"

Model::Model() { initialise(); }

Model::~Model() { terminate(); }

void Model::add_variable(const ModelVariable &variable) { variables.push_back(variable); }

void Model::initialise()
{
    // Create a set of inputs
    for (int i = 0; i < 3; ++i)
    {
        variables.push_back(create_variable(static_cast<ModelVariableType>(i), ModelVariableIntent::Input));
    }

    // Create a set of outputs
    for (int i = 0; i < 3; ++i)
    {
        variables.push_back(create_variable(static_cast<ModelVariableType>(i), ModelVariableIntent::Output));
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
        if (variable.intent == ModelVariableIntent::Output)
        {
            switch (variable.type)
            {
                case ModelVariableType::Int:
                    variable.value = std::get<int>(variable.value) + 1;
                    break;
                case ModelVariableType::Float:
                    variable.value = std::get<float>(variable.value) + 1.0f;
                    break;
                case ModelVariableType::Double:
                    variable.value = std::get<double>(variable.value) + 1.0;
                    break;
            }
        }
    }
}

void Model::terminate() { variables.clear(); }

ModelVariable Model::create_variable(ModelVariableType type, ModelVariableIntent intent)
{
    // Determine default value based on type
    std::string name;
    std::variant<int, float, double> value;
    switch (type)
    {
        case ModelVariableType::Int:
            value = 1;
            name = "int";
            break;
        case ModelVariableType::Float:
            value = 1.0f;
            name = "float";
            break;
        case ModelVariableType::Double:
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
        case ModelVariableIntent::Input:
            prefix = "i_";
            break;
        case ModelVariableIntent::Output:
            prefix = "o_";
            break;
        default:
            prefix = "undef_";
    }
    name = prefix + name;

    // Construct GSMP_VariableType
    return {name, type, value, intent};
}
