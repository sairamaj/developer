single responsible
    - single reason to change
    - separation of concerns
open, closed principle
   - open for extension and closed for modifications
Liskov substituion principle
    - should be able to substitue base type Using custom caching
Interface segragration
    - interfaces should be separated.
    - YAGNI (you are not going to need it) 
    - Dont put too much in to an interface.split into separate interfaces.
Dependency Inversion
    - High level components should not dependent on low level components directly instead should depend on abstractions.
-------------

Gamma categorization
* Creational 
   * construction
   * explicit vs implicit
   * wholesale(single statement) vs piecewise(step-by-step) 
* Structural
   * concerned with structure (class members)
   * stess on api good design
* Behavioral
_______

## Creational
* Builder
   * separate component for building an object.
   * make builder fluent.
   * reduces constructor with lot of patterns.
   * when piecewise object construction is complicaetd provide an API for doing it succinctly.
   * ex: StringBuilder, HtmlBuilder, Autofac.ContainerBuilder
   * step wise
     * use interfaces.
   * funtional builder

______

* Factory
   * responsible solely for the wholesale (not piecewise) creation of objects.
 * object tracking and bulk replacement
   * ex: Task.Factory
 * Abstract factory

____

* Prototype
  * A partially or fully initialized object that you copy (clone) and make use of it.
  * IClonable is bad
    * Type info 
    * Don't know shallow / deep
  * Copy through serialization process.
    * Binary formatter require [Serializer] attribute
    * Xml serializer require default construtor
    * Json serializer ....
_____

* Singleton
  * Instantiated only once.
  * Not recommended.
  * .NET
    * Lazy<>
  * Testability issues
  * Use Autofac (or any DI) to create single instance 
  * Monostate is another single pattern 
    * uses static members
  * Per thread singleton
    * Uses thread local storage.
    * ThreadLocal<>
  * Ambient context
    * like HttpContext.
______

## Structural
* Adapter
  * Similar to power adapter
  * A construct which adapts an existing niterface X to conform to the required interface Y.
_____________
* Bridge
 * A mechanism that decouples an interface (hierarchy) from an implementation(hierarchy) (note: hierarchy)

_____
* Composite
 * used to treat both single(scalar) and composite objects uniformly
   * like shape and group of shapes.
   * compositespecification
_______

* Decorator
  * Adding behaviour on side. Augment an object with additional functionality
  * Adapter-Builder (2 in one)
  * Extension methods add behavior (but not decorator)
________
* Facade
  * Provides a simple easy to understand/user interface over a large and sophisticated body of code.
_____
* FlyWeight
  * Space optimization technique that uses less memory for storing externally the data associated with objects
  * .NET string interning.
______
* Proxy
  * A class that functions as interface to particular resource.That resource may be remote, expensive to construct or may be logging or some other functionality.
  * Proxy vs Decorator
    * Proxy provides identical interface, decorator provides an enhanced interface
    * Decorator typically aggregates (or has reference to) what it is decorating;proxy does not have to.
    * Proxy might not even be working with a materialized object.
  * MVVM
_____

* Chain of responsibility (pipeline)
 * A Chain of components who get a chance to process command or a query, optionally having default processing implemenation and an ability to terminate the processing chain
   * Click a graphical element on a form
     * Button handles it, stop further processing
     * Next Group box 
     * Next window
  * Command Query separation
  * Method Chain

  * [.NET Things: Pipeline Design Pattern](https://medium.com/pragmatic-programming/net-things-pipeline-design-pattern-bb27e65e741e#:~:text=The%20pipeline%20%28or%20chain%20of%20responsibility%29%20design%20pattern,modular%20add-on%20components%20that%20extend%20the%20ASP.NET%20framework.)
_____________

* Command
 * An object which represents an instruction to perform a particular action. Contains all the information necessary for the action to be taken.
_____

* Interpreter
  * A component that processes structured text data. Does so by turning it into separate lexical tokens(lexing) and then interpreting sequences of said tokens(parsing)
  * Examples
    * Programming language compilers
    * HTML, XML
    * Numeric expression (3+4/5)
    * Regular expressions
  * Lexers, Parser
  * ANTLR (Another Tool for Language Recognition)
_____

* Iterator
  * An object(or in .NET, a method) that faciliates the traversal of a data structure.
  * _iterator_ is a class that facilitates the traversal.
  * example: IEnumerable<T> 
______

* Mediator
  * A component that facilitates to communication between them without them necessarily being aware of each other or having direct (reference) access to each other
  * Chat room
  * Event broker
  * MediatR package
______

* Momento
  * A token/handle representing the system state. Lets us rollback to the state when the token was generated. May or may not diretly expose state information.
_____

* Null Object
  * An no-op object that conforms to the required interface, sastisying a dependency requirement of some other object.

_____

* Observer
  * An observer is an object that wises to be informed about events happening in th system. Theentity generating the events is observable.
  * IObservable<T>
  * _INotifyPropertyChanged_
  * _event_ in .NET 

________

* State
  * A pattern in which the object's behavior is determined by its state. An object transitions from one state to another (something needs to be trigger a transition). A formalized construct which manages state and transition is called state machine.
_____

* Strategy (Policy)
  * Enables the exact behavior of a system to be selected either at runtime(dynamic) or at compile time(static).

_____

* Template
  * Allows us to define the 'skeleton' of the algorithm, with concrete implementations defined in subclasses.
  * Define algorithm at high level
  * Define constituent parts as abstract methods/properties
  * Inherit the algorithm class, providing necessary overrides
_____

* Visitor
  * A pattern where a component(visitor) to traverse the entire inheritance hierarchy.Implemented by propagating single method Visit() throughout entire hierarchy.
  * Add functionality to hierarchy of classes without modifying them.
  * Reduce,Map,Transform can be implemented using Visitor.

______

* Creational
  * Builder
  * Factories
  * Prototype
  * Singleton
* Structural
  * Adapter
  * Bridge
  * Composite
  * Decorator
  * Facade
  * Flyweight
  * Proxy
* Behavioral
  * Chain of responsibility
  * Command
  * Interpreter
  * Iterator
  * Mediator
  * Memento
  * Observer
  * State
  * Strategy & Template method
    * Strategy uses composition, Template method uses inheritance
  * Visitor

____

* Duct Type 
  * GetEnumerator()  (foreach)
  * Dispose()  using
* Mixin


