namespace GSMP.Model.CSharp;

/// <summary>
/// Represents a C# model within the GSMP framework, inheriting from the Model class.
/// </summary>
public class CSharpModel : Model
{
    /// <summary>
    /// Represents the current simulation time in the model.
    /// </summary>
    public double Time;

    /// <summary>
    /// Represents a discrete interval of time used within the <see cref="CSharpModel"/>.
    /// This variable is primarily used to advance the model's time state by a fixed increment
    /// during each step of the simulation.
    /// </summary>
    public double TimeStep;

    /// <summary>
    /// Represents a model in the GSMP framework designed for C#.
    /// </summary>
    private CSharpModel()
    {
        GenerateInputsOutputs();
    }

    /// <summary>
    /// Retrieves a variable from the model based on the provided variable name.
    /// </summary>
    /// <param name="variableName">The name of the variable to retrieve.</param>
    /// <returns>The matching variable if found; otherwise, throws an InvalidOperationException.</returns>
    /// <exception cref="InvalidOperationException">Thrown when the variable is not found in the model.</exception>
    public override IModelVariable GetVariableFromModel(string variableName)
    {
        return Variables.Find(variable => variable.Name == variableName) ??
               throw new InvalidOperationException("Variable not found in model.");
    }

    /// <summary>
    /// Initializes the CSharpModel by generating the necessary input and output variables.
    /// </summary>
    public override void Initialize() => GenerateInputsOutputs();

    /// <summary>
    /// Reinitializes the model by regenerating all input and output variables.
    /// This method is typically called to reset the model's state to its initial configuration
    /// while preserving the overall structure of the model.
    /// </summary>
    public override void Reinitialize() => GenerateInputsOutputs();

    /// <summary>
    /// Executes the model step, advancing the state of the model by applying a random increment
    /// to each variable's current value. The increment is a random double between 0 and 10 added
    /// to the current value of the variable. If the current value is of a type that does not
    /// support addition with double, it remains unchanged.
    /// </summary>
    public override void Step() => AddRandomIncrement();

    /// <summary>
    /// Terminates the model execution, performing any necessary cleanup or final operations.
    /// </summary>
    public override void Terminate() => throw new NotImplementedException();

    /// <summary>
    /// Generates the input and output variables for the model.
    /// This method initializes both input and output variables of types int, float, and double,
    /// and adds them to the model's variable collection.
    /// </summary>
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

    /// <summary>
    /// Adds a random increment to each variable's current value in the model.
    /// </summary>
    /// <remarks>
    /// The increment values are generated randomly between 0 and 10.
    /// Each variable's current value is updated based on its type:
    /// - For integers, the random value is cast to an integer before addition, etc.
    /// </remarks>
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
