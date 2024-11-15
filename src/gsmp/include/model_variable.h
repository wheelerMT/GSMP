#ifndef MODEL_VARIABLE_H
#define MODEL_VARIABLE_H

#include <string>
#include <variant>

enum class ModelVariableIntent { Input, Output, Override, Undefined = -1 };
using GSMPType = std::variant<int, float, double>; // All GSMP supported types

class ModelVariable {
public:
    template<typename T>
    ModelVariable(std::string name, T value, ModelVariableIntent intent, std::string description = "") :
        _name(std::move(name)), _intent(intent), _value(value), _description(std::move(description))
    {
        static_assert(std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, double>,
                      "ModelVariable only supports int, float, or double types.");
    }

    template<typename T>
    T get_value() const;

    template<typename T>
    void set_value(T new_value);

    [[nodiscard]] std::string get_type_string() const;

    template<typename T>
    T as() const;

    [[nodiscard]] std::string name() const { return _name; }
    [[nodiscard]] ModelVariableIntent intent() const { return _intent; }
    [[nodiscard]] const GSMPType &get_value() const { return _value; }
    [[nodiscard]] std::string description() const { return _description; }

private:
    std::string _name;
    ModelVariableIntent _intent;
    GSMPType _value;
    std::string _description;
};

#endif // MODEL_VARIABLE_H
