#include "variable_manager.h"
#include <format>

std::list<ModelVariable> VariableManager::variables() const
{
    std::list<ModelVariable> result;

    for (const auto &[name, variable]: _variables)
    {
        result.emplace_back(variable);
    }

    return result;
}

void VariableManager::add_variable(const ModelVariable &variable)
{
    auto [it, success] = _variables.emplace(variable.name(), variable);

    if (!success)
    {
        throw std::runtime_error(std::format("Variable '{}' already exists", it->first));
    }
}

ModelVariable VariableManager::get_variable(const std::string &name) const
{
    try
    {
        return _variables.at(name);
    } catch (const std::out_of_range &)
    {
        throw std::runtime_error(std::format("Variable '{}' does not exist within list of model variables", name));
    }
}

void VariableManager::update_variable(const std::string &name, const GSMPType &value)
{
    try
    {
        _variables.at(name).set_value(value);
    } catch (const std::out_of_range &)
    {
        throw std::runtime_error(std::format("Variable '{}' does not exist within list of model variables", name));
    }
}

void VariableManager::clear() { _variables.clear(); }
