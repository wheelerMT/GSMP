namespace GSMP.Model.CSharp;

public class CSharpModel : Model
{
    private CSharpModel()
    {
        GenerateInputsOutputs();
    }

    public override IModelVariable GetVariableFromModel(string variableName)
    {
        return Variables.Find(variable => variable.Name == variableName) ??
               throw new InvalidOperationException("Variable not found in model.");
    }

    public override void Initialize() => GenerateInputsOutputs();

    public override void Reinitialize() => GenerateInputsOutputs();

    public override void Step() => AddRandomIncrement();

    public override void Terminate() => throw new NotImplementedException();

    private void GenerateInputsOutputs()
    {
        // Generate new int, float and double inputs
        ModelVariable<int> iInt = new("iInt", VariableIntent.Input, 1);
        ModelVariable<float> iFloat = new("iFloat", VariableIntent.Input, 10.0f);
        ModelVariable<double> iDouble = new("iDouble", VariableIntent.Input, 100.0);

        // Generate new int, float and double outputs
        ModelVariable<int> oInt = new("oInt", VariableIntent.Output, 0);
        ModelVariable<float> oFloat = new("oFloat", VariableIntent.Output, 0.0f);
        ModelVariable<double> oDouble = new("oDouble", VariableIntent.Output, 0.0);

        // Add inputs/outputs to Variables list
        AddVariableRange([iInt, iFloat, iDouble, oInt, oFloat, oDouble]);
    }

    private void AddRandomIncrement()
    {
        foreach (var variable in Variables)
        {
            double randomValue = new Random().NextDouble() * 10;
            variable.CurrentValue = variable.CurrentValue switch
            {
                int intValue => (intValue + (int)randomValue),
                float floatValue => (floatValue + (float)randomValue),
                double doubleValue => (doubleValue + randomValue),
                _ => variable.CurrentValue
            };
        }
    }
}
