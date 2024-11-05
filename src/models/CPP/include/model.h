#ifndef MODEL_H
#define MODEL_H
#include <list>
#include <unordered_map>
#include "model_variable.h"

class Model {
public:
    Model();

    ~Model();

    void add_variable(const ModelVariable &variable);

    void initialise();

    void reinitialise();

    void step();

    void terminate();

    std::list<ModelVariable> variables() const;

    ModelVariable get_variable(const std::string &name) const;

    void update_variable(std::string name, GSMPType value);

private:
    std::unordered_map<std::string, ModelVariable> _variables;
};

#endif // MODEL_H
