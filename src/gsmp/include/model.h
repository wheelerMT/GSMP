#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include "variable_manager.h"

class Model {
public:
    Model();

    ~Model();

    void initialise();

    void reinitialise();

    void step();

    void terminate() const;

    [[nodiscard]] const VariableManager *variables() const;

private:
    std::unique_ptr<VariableManager> _variables = std::make_unique<VariableManager>();
};

#endif // MODEL_H
