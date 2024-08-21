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
    object GetValue(); // TODO Current/Default
    void SetValue(object value); // TODO Current/Default
}

// Generic IModelVariable<T> interface
public interface IModelVariable<T> : IModelVariable
{
    T DefaultValue { get; }
    T CurrentValue { get; set; }
}
