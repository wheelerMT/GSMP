#ifndef GSMP_MODEL_TYPES_H
#define GSMP_MODEL_TYPES_H

#include <string>
#include <variant>
#include <iostream>

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      GSMP MODEL ENUMERATIONS                   │ */
/* └────────────────────────────────────────────────────────────────┘ */

enum class GSMP_VariableType {
    Int = 1,
    Float,
    Double
};

enum class GSMP_VariableIntent {
    Input,
    Output,
    Override,
    Undefined = -1
};

// TODO: Implement Return Codes
enum class GSMP_Return {
    OK = 0,
    ERROR = -1,
    PENDING = 1
};

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                     GSMP MODEL VARIABLE TYPES                  │ */
/* └────────────────────────────────────────────────────────────────┘ */

class GSMP_Variable {
public:
    GSMP_Variable(std::string name, GSMP_VariableType type, std::variant<int, float, double> value,
                  GSMP_VariableIntent intent, std::string description = ""
    )
        : name(std::move(name)), type(type), intent(intent), value(std::move(value)),
          description(std::move(description))
    {
    }

    std::string name;
    GSMP_VariableType type;
    GSMP_VariableIntent intent;
    std::variant<int, float, double> value;
    std::string description;
};

#endif // GSMP_MODEL_TYPES_H
