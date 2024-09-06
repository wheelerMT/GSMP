namespace GSMP.Model;

public interface IModel
{
    List<IModelVariable> Variables { get; }

    // Model Setup Calls

    public void LoadModel();
    public IModelVariable GetVariableFromModel(string variableName);

    public void AddVariable(IModelVariable variable);

    // Model Runtime Calls

    public void Initialize();
    public void Reinitialize();
    public void Step();
    public void Terminate();
}
