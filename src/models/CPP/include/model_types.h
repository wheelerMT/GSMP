#ifndef MODEL_TYPES_H
#define MODEL_TYPES_H

#include <string>
#include <variant>

enum class ModelVariableType { Int, Float, Double };

enum class ModelVariableIntent { Input, Output, Override, Undefined = -1 };

class ModelVariable {
public:
    ModelVariable(std::string name, ModelVariableType type, std::variant<int, float, double> value,
                  ModelVariableIntent intent, std::string description = "") :
        name(std::move(name)), type(type), intent(intent), value(value), description(std::move(description))
    {
    }

    std::string name;
    ModelVariableType type;
    ModelVariableIntent intent;
    std::variant<int, float, double> value;
    std::string description;
};

#endif // MODEL_TYPES_H
