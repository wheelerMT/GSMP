#ifndef MODEL_H
#define MODEL_H
#include <list>
#include "GSMP_model_types.h"

class Model {
public:
    std::list<GSMP_Variable> variables;

    Model();

    ~Model();

    /* ┌────────────────────────────────────────────────────────────────┐ */
    /* │                      Model Backend Setup                       │ */
    /* └────────────────────────────────────────────────────────────────┘ */

    // Add a variable to the model list
    void AddVariable(const GSMP_Variable &variable);

    /* ┌────────────────────────────────────────────────────────────────┐ */
    /* │                      Model Runtime                             │ */
    /* └────────────────────────────────────────────────────────────────┘ */

    void initialise();

    void reinitialise();

    void step() const;

    void terminate();

private:
    // Helper function for creating a variable
    static GSMP_Variable createVariable(GSMP_VariableType type, GSMP_VariableIntent intent);
};
#endif //MODEL_H
