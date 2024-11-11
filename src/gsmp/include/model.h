#ifndef MODEL_H
#define MODEL_H
#include "variable_manager.h"

class Model {
public:
    Model();

    ~Model();

    void initialise();

    void reinitialise();

    void step();

    void terminate();

    const VariableManager &variables() const;

private:
    VariableManager _variables;
};

#endif // MODEL_H
