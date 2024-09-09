namespace GSMP.Model.CSharp.Tests;

[TestFixture]
public class CSharpModelTests
{
    private CSharpModel _model;

    [SetUp]
    public void SetUp()
    {
        _model = new CSharpModel();
    }

    [Test]
    public void Initialize_ShouldGenerateInputsOutputs()
    {
        Assert.Multiple(() =>
        {
            Assert.That(_model.Variables, Has.Count.EqualTo(6));
            Assert.That(_model.Variables.FirstOrDefault(v => v.Name == "iInt"), Is.Not.Null);
            Assert.That(_model.Variables.FirstOrDefault(v => v.Name == "iFloat"), Is.Not.Null);
            Assert.That(_model.Variables.FirstOrDefault(v => v.Name == "iDouble"), Is.Not.Null);
            Assert.That(_model.Variables.FirstOrDefault(v => v.Name == "oInt"), Is.Not.Null);
            Assert.That(_model.Variables.FirstOrDefault(v => v.Name == "oFloat"), Is.Not.Null);
            Assert.That(_model.Variables.FirstOrDefault(v => v.Name == "oDouble"), Is.Not.Null);
        });
    }

    [Test]
    public void GetVariableFromModel_ShouldReturnVariable_WhenVariableExists()
    {
        var variable = _model.GetVariableFromModel("iInt");

        Assert.That(variable, Is.Not.Null);
        Assert.That(variable.Name, Is.EqualTo("iInt"));
    }

    [Test]
    public void GetVariableFromModel_ShouldThrowException_WhenVariableDoesNotExist()
    {
        Assert.Throws<InvalidOperationException>(() => _model.GetVariableFromModel("NonExistingVariable"));
    }

    [Test]
    public void Step_ShouldAddRandomIncrementToVariableValues()
    {
        var initialValues = _model.Variables.ToDictionary(v => v.Name, v => v.CurrentValue);

        _model.Step();

        foreach (var variable in _model.Variables)
        {
            object initialValue = initialValues[variable.Name];
            Assert.That(variable.CurrentValue, Is.Not.EqualTo(initialValue));
        }
    }

    [Test]
    public void Reinitialize_ShouldResetVariables()
    {
        _model.Step();
        var initialValuesPostStep = _model.Variables.ToDictionary(v => v.Name, v => v.CurrentValue);

        _model.Reinitialize();

        foreach (var variable in _model.Variables)
        {
            Assert.That(variable.CurrentValue, Is.Not.EqualTo(initialValuesPostStep[variable.Name]));
        }
    }
}
