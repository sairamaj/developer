# Basics
__IMPORTANT__: Rhino.Mocks can only mock/stub __virtual__ members of a real class, so make sure the members you care about are virtual -- OR, event better, mock/stub an Interface, in which case you can do whatever you want.

## Stubs vs Mocks
* A __stub__ is simply an alternate implementation. A __mock__, however, is more than that. A mock sets up an expectation that
* A specific method will be called
* It will be called with the provided inputs
* It will return the provided results

## Mock Options
### Strict Mock
*  require alternative implementations for each method/property that is used on mock.
### Dynamic Mock
*  any methods/properties which are called by your tests for which you have not provided an implementation will return the default value for the data type of the return value. ( __0__ or for numbers __false__ for booleans and __null__ for other types)
### Partial Mock
* will use the underlying object's implementation if you don't provide an alternative implementation.


## Generating a stub
```csharp
    var car = MockRepository.GenerateMock<ICar>();  // (dynamic mocks)
    var car = MockRepository.GeneratePartialMock<ICar>();
    var car = MockRepository.GenerateStrictMock<ICar>();
```

## Mocking
```csharp
    car.Stub(c => c.Start()).Return(false);
```
### Constraint
Constraints are a way to verify that a method's arguments match a certain criteria. Rhino Mocks includes a number of built-in constraints, and allows you to define you own custom ones, which will integrate cleanly into the framework. You specify constraints on method arguments using the following syntax:

```csharp
Expect.Call(view.Ask(null,null)).IgnoreArguments().Constraints(
   Is.Anything(), Is.TypeOf(typeof(SomeType))).Return(null)
```
[source](https://ayende.com/wiki/Rhino+Mocks+Constraints.ashx?AspxAutoDetectCookieSupport=1)


## Resources
* [Ayende](https://ayende.com/wiki/MainPage.ashx)
* [Using Rhino.Mocks - quick guide to generating mocks and stubs](http://www.wrightfully.com/using-rhino-mocks-quick-guide-to-generating-mocks-and-stubs/)
* [HOW TO USE RHINO MOCKS – DOCUMENTED THROUGH TESTS](http://jonkruger.com/blog/2010/03/12/how-to-use-rhino-mocks-documented-through-tests/)