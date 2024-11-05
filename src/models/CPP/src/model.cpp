#include "model.h"
#include <format>
#include <stdexcept>
#include "model_variable.h"

Model::Model() { initialise(); }

Model::~Model() { terminate(); }

void Model::add_variable(const ModelVariable &variable)
{
    auto [it, success] = _variables.emplace(variable.name(), variable);

    if (!success)
    {
        throw std::runtime_error(std::format("Variable '{}' already exists", it->first));
    }
}

void Model::initialise()
{
    // Initialise all model variables
}

void Model::reinitialise()
{
    _variables.clear();
    initialise();
}

void Model::step()
{
    // Step the model and update variables accordingly
}

void Model::terminate() { _variables.clear(); }

std::list<ModelVariable> Model::variables() const
{
    std::list<ModelVariable> result;

    for (const auto &[name, variable]: _variables)
    {
        result.emplace_back(variable);
    }

    return result;
}

ModelVariable Model::get_variable(const std::string &name) const
{
    try
    {
        return _variables.at(name);
    } catch (const std::out_of_range &)
    {
        throw std::runtime_error(std::format("Variable '{}' does not exist within list of model variables", name));
    }
}
