using System.Collections;

namespace GSMP.Model;

public class ModelVariable<T> : IModelVariable<T>
{
    public string Name { get; }
    public VariableIntent Intent { get; }
    public T DefaultValue { get; }
    public T CurrentValue { get; set; }

    object IModelVariable.CurrentValue
    {
        get => CurrentValue ?? throw new InvalidOperationException("Current value is null");
        set => CurrentValue = (T)value;
    }

    public Type Type { get; }
    public string Description { get; }
    public IReadOnlyList<int>? Dimensions { get; }

    public ModelVariable(string name, VariableIntent intent, T defaultValue, string description = "")
    {
        ValidateName(name);
        ValidateIntent(intent);

        Name = name;
        Intent = intent;
        DefaultValue = defaultValue;
        CurrentValue = defaultValue;
        Type = typeof(T);
        Description = description;
        Dimensions = CalculateDimensions(defaultValue);
    }

    private static void ValidateName(string name)
    {
        if (string.IsNullOrWhiteSpace(name))
            throw new ArgumentException("Name cannot be null or empty.", nameof(name));
    }

    private static void ValidateIntent(VariableIntent intent)
    {
        if (!Enum.IsDefined(typeof(VariableIntent), intent))
            throw new ArgumentException("Invalid VariableIntent value.", nameof(intent));
    }

    private static int[]? CalculateDimensions(T value)
    {
        return value switch
        {
            Array { Rank: > 1 } array => Enumerable.Range(0, array.Rank).Select(array.GetLength).ToArray(),
            Array array => [array.Length],
            IList list => [list.Count],
            _ => null
        };
    }

    public void ResetToDefault() => CurrentValue = DefaultValue;

    public override string ToString() =>
        $"{Name} ({Intent}): {CurrentValue} (Default: {DefaultValue})";
}

public enum VariableIntent
{
    Undefined = 0,
    Input,
    Output,
    Override,
}
