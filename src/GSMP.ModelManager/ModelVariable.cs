namespace GSMP.ModelManager;

public record ModelVariable<T> where T : new()
{
    public string Name { get; init; } = "";
    public string Description { get; init; } = "";
    public Type Type { get; init; } = typeof(T);
    public VariableIntent Intent { get; init; } = VariableIntent.Undefined;
    public T DefaultValue { get; init; } = new T();
    public List<int> Dimensions { get; init; } = [];
}

public enum VariableIntent
{
    Undefined,
    Input,
    Output,
    Override,
}