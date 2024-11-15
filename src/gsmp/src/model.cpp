#include "model.h"

Model::Model() { initialise(); }

Model::~Model() { terminate(); }

void Model::initialise()
{
    // Initialise all model variables
}

void Model::reinitialise()
{
    _variables->clear();
    initialise();
}

void Model::step()
{
    // Step the model and update variables accordingly
}

void Model::terminate() const { _variables->clear(); }

const VariableManager *Model::variables() const { return _variables.get(); }
