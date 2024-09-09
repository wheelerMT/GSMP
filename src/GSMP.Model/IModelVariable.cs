namespace GSMP.Model;

// Non-generic IModelVariable interface
public interface IModelVariable
{
    string Name { get; }
    VariableIntent Intent { get; }
    Type Type { get; }
    string Description { get; }
    IReadOnlyList<int>? Dimensions { get; }
    void ResetToDefault();
    object CurrentValue { get; set; }
}

// Generic IModelVariable<T> interface
public interface IModelVariable<T> : IModelVariable
{
    T DefaultValue { get; }
    new T CurrentValue { get; set; }
}
