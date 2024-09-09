﻿namespace GSMP.Model;

public abstract class Model : IModel
{
    // List of all ModelVariables
    public List<IModelVariable> Variables { get; } = [];

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      Model Backend Setup                       │ */
/* └────────────────────────────────────────────────────────────────┘ */

    // Get the metadata about a specific variable, then construct it into a ModelVariable
    public abstract IModelVariable GetVariableFromModel(string variableName);

    // Adds a ModelVariable to the Variable list
    public virtual void AddVariable(IModelVariable variable)
    {
        Variables.Add(variable);
    }

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      Model Runtime                             │ */
/* └────────────────────────────────────────────────────────────────┘ */

    // Implementation for initialization
    public abstract void Initialize();

    // Implementation for reinitialization
    public abstract void Reinitialize();

    // Implementation for a step in the model
    public abstract void Step();

    // Implementation for termination
    public abstract void Terminate();
}
