namespace GSMP.ModelManager.Tests;

[TestFixture]
public class ModelVariableTests
{
    [Test]
    public void Constructor_ValidInput_CreatesInstance()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, -1, new[] { 1 }, "Test description");

        Assert.That(variable.Name, Is.EqualTo("TestVar"));
        Assert.That(variable.Intent, Is.EqualTo(VariableIntent.Input));
        Assert.That(variable.DefaultValue, Is.EqualTo(-1));
        Assert.That(variable.CurrentValue, Is.EqualTo(-1));
        Assert.That(variable.Type, Is.EqualTo(typeof(int)));
        Assert.That(variable.Description, Is.EqualTo("Test description"));
        Assert.That(variable.Dimensions, Is.EqualTo(new[] { 1 }));
    }

    [Test]
    public void Constructor_EmptyName_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() => new ModelVariable<int>("", VariableIntent.Input, 0, new[] { 1 }));
    }

    [Test]
    public void Constructor_InvalidIntent_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() => new ModelVariable<int>("TestVar", (VariableIntent)999, 0, new[] { 1 }));
    }

    [Test]
    public void Constructor_EmptyDimensions_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() =>
            new ModelVariable<int>("TestVar", VariableIntent.Input, 0, Array.Empty<int>()));
    }

    [Test]
    public void Constructor_NegativeDimension_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() =>
            new ModelVariable<int>("TestVar", VariableIntent.Input, 0, new[] { -1 }));
    }

    [Test]
    public void Constructor_ArrayDefaultValue_MatchingDimensions_CreatesInstance()
    {
        var variable = new ModelVariable<int[,]>("TestVar", VariableIntent.Input, new int[2, 3], new[] { 2, 3 });
        Assert.That(variable.Dimensions, Is.EqualTo(new[] { 2, 3 }));
    }

    [Test]
    public void Constructor_ArrayDefaultValue_MismatchedDimensions_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() =>
            new ModelVariable<int[,]>("TestVar", VariableIntent.Input, new int[2, 3], new[] { 3, 2 }));
    }

    [Test]
    public void Constructor_NonArrayDefaultValue_NonScalarDimensions_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() =>
            new ModelVariable<int>("TestVar", VariableIntent.Input, 0, new[] { 2, 3 }));
    }

    [Test]
    public void ResetToDefault_SetsCurrentValueToDefaultValue()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, 0, new[] { 1 }) { CurrentValue = 5 };
        variable.ResetToDefault();
        Assert.That(variable.CurrentValue, Is.EqualTo(variable.DefaultValue));
    }

    [Test]
    public void ToString_ReturnsExpectedString()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, 0, new[] { 1 });
        Assert.That(variable.ToString(), Is.EqualTo("TestVar (Input): 0 (Default: 0)"));
    }

    [Test]
    public void CurrentValue_CanBeSet()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, 0, new[] { 1 }) { CurrentValue = 5 };
        Assert.That(variable.CurrentValue, Is.EqualTo(5));
    }
}
