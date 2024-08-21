namespace GSMP.Model.Tests;

[TestFixture]
public class ModelVariableTests
{
    [Test]
    public void Constructor_ValidInput_CreatesInstance()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, -1, "Test description");

        Assert.Multiple(() =>
        {
            Assert.That(variable.Name, Is.EqualTo("TestVar"));
            Assert.That(variable.Intent, Is.EqualTo(VariableIntent.Input));
            Assert.That(variable.DefaultValue, Is.EqualTo(-1));
            Assert.That(variable.CurrentValue, Is.EqualTo(-1));
            Assert.That(variable.Type, Is.EqualTo(typeof(int)));
            Assert.That(variable.Description, Is.EqualTo("Test description"));
            Assert.That(variable.Dimensions, Is.EqualTo(null));
        });
    }

    [Test]
    public void Constructor_EmptyName_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() => new ModelVariable<int>("", VariableIntent.Input, 0));
    }

    [Test]
    public void Constructor_InvalidIntent_ThrowsArgumentException()
    {
        Assert.Throws<ArgumentException>(() => new ModelVariable<int>("TestVar", (VariableIntent)999, 0));
    }

    [Test]
    public void Constructor_ScalarValue_DimensionsAreNull()
    {
        var variable = new ModelVariable<int>("ScalarInt", VariableIntent.Input, 42);
        Assert.IsNull(variable.Dimensions);
    }

    [Test]
    public void Constructor_SingleDimensionArray_ReturnsCorrectDimensions()
    {
        int[] array = [1, 2, 3, 4, 5, 6];
        var variable = new ModelVariable<int[]>("OneDArray", VariableIntent.Input, array);
        Assert.That(variable.Dimensions, Is.EquivalentTo(new[] { 6 }));
    }

    [Test]
    public void Constructor_TwoDimensionArray_ReturnsCorrectDimensions()
    {
        int[,] array = { { 1, 2, 3 }, { 4, 5, 6 } };
        var variable = new ModelVariable<int[,]>("TwoDArray", VariableIntent.Input, array);
        Assert.That(variable.Dimensions, Is.EquivalentTo(new[] { 2, 3 }));
    }

    [Test]
    public void Constructor_JaggedArray_ReturnsToplevelDimension()
    {
        int[][] jaggedArray = [[1, 2, 3], [4, 5, 6, 7]];
        var variable = new ModelVariable<int[][]>("JaggedArray", VariableIntent.Input, jaggedArray);
        Assert.That(variable.Dimensions, Is.EquivalentTo(new[] { 2 }));
    }

    [Test]
    public void Constructor_List_ReturnsCorrectDimension()
    {
        var list = new List<string> { "a", "b", "c", "d" };
        var variable = new ModelVariable<List<string>>("StringList", VariableIntent.Input, list);
        Assert.That(variable.Dimensions, Is.EquivalentTo(new[] { 4 }));
    }

    [Test]
    public void Constructor_EmptyArray_ReturnsZeroDimension()
    {
        int[] emptyArray = [];
        var variable = new ModelVariable<int[]>("EmptyArray", VariableIntent.Input, emptyArray);
        Assert.That(variable.Dimensions, Is.EquivalentTo(new[] { 0 }));
    }

    [Test]
    public void Constructor_EmptyList_ReturnsZeroDimension()
    {
        var emptyList = new List<double>();
        var variable = new ModelVariable<List<double>>("EmptyList", VariableIntent.Input, emptyList);
        Assert.That(variable.Dimensions, Is.EquivalentTo(new[] { 0 }));
    }

    [Test]
    public void Constructor_ThreeDimensionArray_ReturnsCorrectDimensions()
    {
        int[,,] array = new int[2, 3, 4];
        var variable = new ModelVariable<int[,,]>("ThreeDArray", VariableIntent.Input, array);
        Assert.That(variable.Dimensions, Is.EquivalentTo(new[] { 2, 3, 4 }));
    }

    [Test]
    public void ResetToDefault_SetsCurrentValueToDefaultValue()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, 0) { CurrentValue = 5 };
        variable.ResetToDefault();
        Assert.That(variable.CurrentValue, Is.EqualTo(variable.DefaultValue));
    }

    [Test]
    public void ToString_ReturnsExpectedString()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, 0);
        Assert.That(variable.ToString(), Is.EqualTo("TestVar (Input): 0 (Default: 0)"));
    }

    [Test]
    public void CurrentValue_CanBeSet()
    {
        var variable = new ModelVariable<int>("TestVar", VariableIntent.Input, 0) { CurrentValue = 5 };
        Assert.That(variable.CurrentValue, Is.EqualTo(5));
    }
}
