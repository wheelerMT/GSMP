#include "model_variable.h"
#include <format>
#include <stdexcept>

template<typename T>
T ModelVariable::get_value() const
{
    return _value;
}

template<typename T>
void ModelVariable::set_value(const T new_value)
{
    // Ensures new value matches the current type
    std::visit(
            [this](const auto &val)
            {
                using NewType = std::decay_t<decltype(val)>;
                if (!std::holds_alternative<NewType>(_value))
                {
                    throw std::runtime_error(std::format("Value {} is not a supported GSMP type", val));
                }
                _value = val;
            },
            new_value);
}

std::string ModelVariable::get_type_string() const
{
    return std::visit(
            [](const auto &arg) -> std::string
            {
                using T = std::decay_t<decltype(arg)>; // Decays "const int&" to just "int", etc.
                if constexpr (std::is_same_v<T, int>)
                    return "int";
                else if constexpr (std::is_same_v<T, float>)
                    return "float";
                else if constexpr (std::is_same_v<T, double>)
                    return "double";
                else
                    return "unknown";
            },
            _value);
}

template<typename T>
T ModelVariable::as() const
{
    return std::visit([](auto &&arg) -> T { return static_cast<T>(arg); }, _value);
}
