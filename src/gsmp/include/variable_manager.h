#ifndef VARIABLE_MANAGER_H
#define VARIABLE_MANAGER_H
#include <list>
#include <string>
#include <unordered_map>
#include "model_variable.h"

class VariableManager {
public:
    VariableManager() = default;
    ~VariableManager() = default;

    std::list<ModelVariable> variables() const;

    void add_variable(const ModelVariable &variable);

    ModelVariable get_variable(const std::string &name) const;

    template<typename T>
    void update_variable(const std::string &name, T value);

    void clear();

private:
    std::unordered_map<std::string, ModelVariable> _variables;
};
#endif // VARIABLE_MANAGER_H
