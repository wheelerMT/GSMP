namespace GSMP.Model;
public interface IModel
{

    // Model Setup Calls

    public void LoadModel();
    public List<IModelVariable> GetVariables();
    public void AddVariable(IModelVariable variable);

    // Model Runtime Calls

    public void Initialize();
    public void Reinitialize();
    public void Step();
    public void Terminate();
}
