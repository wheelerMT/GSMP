namespace GSMP.ModelManager;

public class ModelVariable<T>
{
    public string Name { get; }
    public VariableIntent Intent { get; }
    public T DefaultValue { get; }
    public T CurrentValue { get; set; }
    public Type Type { get; }
    public string Description { get; }
    public IReadOnlyList<int> Dimensions { get; }

    public ModelVariable(string name, VariableIntent intent, T defaultValue,
                         IReadOnlyList<int> dimensions, string description = "")
    {
        ValidateName(name);
        ValidateIntent(intent);
        ValidateDimensions(dimensions);

        Name = name;
        Intent = intent;
        DefaultValue = defaultValue;
        CurrentValue = defaultValue;
        Type = typeof(T);
        Description = description;
        Dimensions = dimensions;

        ValidateDimensions();
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

    private static void ValidateDimensions(IReadOnlyList<int> dimensions)
    {
        if (dimensions == null || dimensions.Count == 0)
            throw new ArgumentException("Dimensions cannot be null or empty.", nameof(dimensions));

        if (dimensions.Any(d => d <= 0))
            throw new ArgumentException("All dimensions must be positive integers.", nameof(dimensions));
    }

    private void ValidateDimensions()
    {
        if (DefaultValue is Array array)
        {
            int[] actualDimensions = Enumerable.Range(0, array.Rank)
                                               .Select(array.GetLength)
                                               .ToArray();

            if (!actualDimensions.SequenceEqual(Dimensions))
                throw new ArgumentException("DefaultValue dimensions do not match specified Dimensions.");
        }
        else if (Dimensions.Count > 1 || Dimensions[0] != 1)
        {
            throw new ArgumentException("Non-array DefaultValue must have Dimensions [1] (a scalar).");
        }
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
