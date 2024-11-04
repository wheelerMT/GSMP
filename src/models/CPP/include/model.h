#ifndef MODEL_H
#define MODEL_H
#include <list>
#include "model_types.h"

class Model {
public:
    std::list<ModelVariable> variables;

    Model();

    ~Model();

    void add_variable(const ModelVariable &variable);

    void initialise();

    void reinitialise();

    void step() const;

    void terminate();

private:
    // Helper function for creating a variable
    static ModelVariable create_variable(ModelVariableType type, ModelVariableIntent intent);
};

#endif // MODEL_H
