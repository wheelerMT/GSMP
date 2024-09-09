namespace GSMP.Model.CSharp;

public class CSharpModel : Model
{
    public override void LoadModel() => GenerateInputsOutputs();

    public override IModelVariable GetVariableFromModel(string variableName)
    {
        return Variables.Find(variable => variable.Name == variableName) ??
               throw new InvalidOperationException("Variable not found in model.");
    }

    public override void Initialize() => GenerateInputsOutputs();

    public override void Reinitialize() => GenerateInputsOutputs();

    public override void Step() => throw new NotImplementedException();

    public override void Terminate() => throw new NotImplementedException();

    private void GenerateInputsOutputs()
    {
        // Generate new int, float and double inputs
        ModelVariable<int> iInt = new ModelVariable<int>("iInt", VariableIntent.Input, 1);
        ModelVariable<float> iFloat = new ModelVariable<float>("iFloat", VariableIntent.Input, 10.0f);
        ModelVariable<double> iDouble = new ModelVariable<double>("iDouble", VariableIntent.Input, 100.0);

        // Generate new int, float and double outputs
        ModelVariable<int> oInt = new ModelVariable<int>("oInt", VariableIntent.Output, 0);
        ModelVariable<float> oFloat = new ModelVariable<float>("oFloat", VariableIntent.Output, 0.0f);
        ModelVariable<double> oDouble = new ModelVariable<double>("oDouble", VariableIntent.Output, 0.0);

        // Add inputs/outputs to Variables list
        Variables.AddRange([iInt, iFloat, iDouble, oInt, oFloat, oDouble]);
    }
}
