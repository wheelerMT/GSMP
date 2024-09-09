namespace GSMP.Model;

public interface IModel
{
    List<IModelVariable> Variables { get; }

/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      Model Setup Calls                         │ */
/* └────────────────────────────────────────────────────────────────┘ */

    public IModelVariable GetVariableFromModel(string variableName);

    // Add a single variable to the variables list
    public void AddVariable(IModelVariable variable);

    // Adds multiple variables to the variables list at once
    public void AddVariableRange(List<IModelVariable> variables);


/* ┌────────────────────────────────────────────────────────────────┐ */
/* │                      Model Runtime Calls                       │ */
/* └────────────────────────────────────────────────────────────────┘ */

    public void Initialize();
    public void Reinitialize();
    public void Step();
    public void Terminate();
}
