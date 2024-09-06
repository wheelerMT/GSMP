namespace GSMP.Model;

public class Model
{
    // List of ModelVariables [Empty]
    // Model Specific Properties or Options
    // Logging Options


    // Model Backend Setup (IModelSetup?)

    public virtual List<IModelVariable> GetVariableInformation()
    {
        // Implementation to get all Model Variable Information
        return [];
    }

    public virtual void RegisterVariableInformation()
    {
        // ARGS: string name, VariableIntent intent, T defaultValue, string description = ""
        // New Variable (ARGS) : Validity
        // Add to List in Model (C#) : Validity - does not exist, is not contradictory
    }

    // Model Runtime (IModelRuntime?)

    public virtual void Initialize()
    {
        // Implementation for initialization
    }

    public virtual void Reinitialize()
    {
        // Implementation for reinitialization
    }

    public virtual void Step()
    {
        // Implementation for a step in the model
    }

    public virtual void Terminate()
    {
        // Implementation for termination
    }
}
