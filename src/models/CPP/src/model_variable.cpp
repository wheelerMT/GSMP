#include "model_variable.h"
#include <format>
#include <stdexcept>

template<typename T>
T ModelVariable::get_value() const
{
    static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>,
                  "Can only retrieve int, float, or double types.");

    try
    {
        return std::get<T>(_value);
    } catch (const std::bad_variant_access &)
    {
        throw std::runtime_error(
                std::format("Stored type does not match the requested type. Stored type index: {}", _value.index()));
    }
}

template<typename T>
void ModelVariable::set_value(T new_value)
{
    static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>,
                  "Can only set int, float, or double types.");
    _value = new_value;
}

std::string ModelVariable::get_type_string() const
{
    if (std::holds_alternative<int>(_value))
        return "int";
    if (std::holds_alternative<float>(_value))
        return "float";
    if (std::holds_alternative<double>(_value))
        return "double";

    return "unknown";
}

template<typename T>
T ModelVariable::as() const
{
    static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>,
                  "Can only convert to int, float, or double types.");
    return std::visit([](auto &&arg) -> T { return static_cast<T>(arg); }, _value);
}
