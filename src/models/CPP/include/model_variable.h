#ifndef MODEL_VARIABLE_H
#define MODEL_VARIABLE_H

#include <stdexcept>
#include <string>
#include <variant>


enum class ModelVariableIntent { Input, Output, Override, Undefined = -1 };
using GSMPType = std::variant<int, float, double>; // All GSMP supported types

class ModelVariable {
public:
    template<typename T>
    ModelVariable(std::string name, T value, ModelVariableIntent intent, std::string description = "") :
        name(std::move(name)), intent(intent), value(value), description(std::move(description))
    {
        static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>,
                      "ModelVariable only supports int, float, or double types.");
    }

    template<typename T>
    T get_value() const
    {
        static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>,
                      "Can only retrieve int, float, or double types.");

        try
        {
            return std::get<T>(value);
        } catch (const std::bad_variant_access &)
        {
            throw std::runtime_error("Stored type does not match the requested type.");
        }
    }

    std::string name;
    ModelVariableIntent intent;
    GSMPType value;
    std::string description;
};

#endif // MODEL_VARIABLE_H
